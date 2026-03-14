#include "../../Server.hpp"
#include "../../Client.hpp"
#include <sstream>

void Server::cmdMode(int fd, const std::vector<std::string>& params)
{
    // MODE без target вообще нельзя
    if (params.size() < 2)
    {
        sendToClient(fd, ":server 461 MODE :Not enough parameters");
        return;
    }

    std::string channelName = params[1];

    // В данном проекте поддерживаем только channel modes (#channel)
    // Если target не канал — возвращаем ошибку
    if (channelName.empty() || channelName[0] != '#')
    {
        sendToClient(fd, ":server 403 " + channelName + " :No such channel");
        return;
    }

    std::map<std::string, Channel>::iterator it = _channels.find(channelName);
    if (it == _channels.end())
    {
        sendToClient(fd, ":server 403 " + channelName + " :No such channel");
        return;
    }

    Channel& channel = it->second;

    std::map<int, Client*>::iterator clientIt = _clients.find(fd); // Ищем отправителя команды
    if (clientIt == _clients.end() || clientIt->second == NULL)
        return;

    Client& sender = *(clientIt->second);

    // -------------------------------------------------
    // 1. Если пришло только MODE #channel
    //    => это запрос текущих mode канала
    // -------------------------------------------------
    if (params.size() == 2)
    {
        std::string currentModes = "+";

        // Проверяем активные режимы
        if (channel.isInviteOnly())
            currentModes += "i";
        if (channel.isTopicRestricted())
            currentModes += "t";
        if (!channel.getKey().empty())
            currentModes += "k";
        if (channel.getLimit() > 0)
            currentModes += "l";

        std::string modeReply = ":server 324 " + sender.getNickname() + " " +
                                channelName + " " + currentModes;

        if (!channel.getKey().empty())
            modeReply += " " + channel.getKey(); // Если есть ключ канала — добавляем его
        if (channel.getLimit() > 0) // Если есть лимит — добавляем число
        {
            std::stringstream ss;
            ss << channel.getLimit();
            modeReply += " " + ss.str();
        }

        sendToClient(fd, modeReply);
        return;
    }

    // -------------------------------------------------
    // 2. Начиная с этого места MODE меняет режимы
    // -------------------------------------------------
    if (!channel.isOperator(fd))
    {
        sendToClient(fd, ":server 482 " + channelName + " :You're not a channel operator");
        return;
    }

    std::string modeChanges = params[2]; // Строка изменений режимов (+i -k +o и т.д.)
    bool adding = true; // Флаг: добавляем режим или убираем
    size_t paramIndex = 3;

    std::string appliedModes = ""; // Какие режимы реально применились
    std::vector<std::string> appliedParams; // Параметры применённых режимов (например key или nick)

    for (size_t i = 0; i < modeChanges.size(); ++i)
    {
        char c = modeChanges[i];

        if (c == '+') // '+' означает добавление режимов
        {
            adding = true;
            appliedModes += c;
        }
        else if (c == '-') // '-' означает снятие режимов
        {
            adding = false;
            appliedModes += c;
        }
        else
        {
            switch (c)
            {
                case 'i':
                    channel.setInviteOnly(adding);
                    appliedModes += 'i';
                    break;

                case 't':
                    channel.setTopicRestricted(adding);
                    appliedModes += 't';
                    break;

                case 'k':
                    if (adding)
                    {
                        if (paramIndex >= params.size())
                        {
                            sendToClient(fd, ":server 461 MODE :Not enough parameters");
                            return;
                        }
                        channel.setKey(params[paramIndex]); // устанавливаем ключ
                        appliedModes += 'k';
                        appliedParams.push_back(params[paramIndex]);
                        paramIndex++;
                    }
                    else
                    {
                        channel.setKey(""); // снимаем ключ
                        appliedModes += 'k';
                    }
                    break;

                case 'l':
                    if (adding)
                    {
                        if (paramIndex >= params.size())
                        {
                            sendToClient(fd, ":server 461 MODE :Not enough parameters");
                            return;
                        }

                        std::stringstream ss(params[paramIndex]);
                        unsigned int limit = 0;
                        ss >> limit;

                        channel.setLimit(limit); // устанавливаем лимит
                        appliedModes += 'l';
                        appliedParams.push_back(params[paramIndex]);
                        paramIndex++;
                    }
                    else
                    {
                        channel.setLimit(0); // убираем лимит
                        appliedModes += 'l';
                    }
                    break;

                case 'o':
                    if (paramIndex >= params.size())
                    {
                        sendToClient(fd, ":server 461 MODE :Not enough parameters");
                        return;
                    }

                    {
                        std::string nick = params[paramIndex];
                        int targetFd = -1;

                        // ищем пользователя по нику
                        for (std::map<int, Client*>::iterator itClient = _clients.begin();
                             itClient != _clients.end(); ++itClient)
                        {
                            if (itClient->second && itClient->second->getNickname() == nick)
                            {
                                targetFd = itClient->first;
                                break;
                            }
                        }

                        if (targetFd == -1 || !channel.hasClient(targetFd)) // пользователь должен быть в канале
                        {
                            sendToClient(fd, ":server 441 " + nick + " " + channelName + " :They aren't on that channel");
                            return;
                        }

                         // добавляем или убираем оператора
                        if (adding)
                            channel.addOperator(targetFd);
                        else
                            channel.removeOperator(targetFd);

                        appliedModes += 'o';
                        appliedParams.push_back(nick);
                        paramIndex++;
                    }
                    break;

                // неизвестный режим
                default:
                    sendToClient(fd, ":server 472 " + std::string(1, c) + " :is unknown mode char to me");
                    return;
            }
        }
    }

    // Если режимы не изменились — ничего не отправляем
    if (appliedModes.empty() || appliedModes == "+" || appliedModes == "-")
        return;

    std::string modeMsg = sender.getPrefix() + " MODE " + channelName + " " + appliedModes;

    for (size_t i = 0; i < appliedParams.size(); ++i) // Добавляем параметры режимов
        modeMsg += " " + appliedParams[i];

    modeMsg += "\r\n";

    const std::set<int>& members = channel.getClients(); // Отправляем MODE всем участникам канала
    for (std::set<int>::const_iterator it2 = members.begin(); it2 != members.end(); ++it2)
        sendToClient(*it2, modeMsg);
}