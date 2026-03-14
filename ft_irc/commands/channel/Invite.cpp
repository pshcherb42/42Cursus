#include "../../Server.hpp"
#include "../../Client.hpp"

void Server::cmdInvite(int fd, const std::vector<std::string>& params)
{
    if (params.size() < 3)
    {
        sendToClient(fd, ":server 461 INVITE :Not enough parameters");
        return;
    }

    std::string nick = params[1]; // Ник пользователя которого приглашаем
    std::string channelName = params[2];

    // Получаем итератор на канал
    std::map<std::string, Channel>::iterator it = _channels.find(channelName);

    if (it == _channels.end())// Проверяем существует ли канал
    {
        sendToClient(fd, ":server 403 " + channelName + " :No such channel");
        return;
    }

    Channel& channel = it->second;


    // Проверка: отправитель в канале
    if (!channel.hasClient(fd))
    {
        sendToClient(fd, ":server 442 " + channelName + " :You're not on that channel");
        return;
    }

    // Проверка: отправитель оператор
    if (!channel.isOperator(fd))
    {
        sendToClient(fd, ":server 482 " + channelName + " :You're not channel operator");
        return;
    }

    // Ищем пользователя по нику среди подключённых клиентов
    int targetFd = -1;
    for (std::map<int, Client*>::iterator it = _clients.begin();
         it != _clients.end(); ++it)
    {
        if (it->second->getNickname() == nick)
        {
            targetFd = it->first;
            break;
        }
    }

    if (targetFd == -1) // Если пользователь с таким ником не найден
    {
        sendToClient(fd, ":server 401 " + nick + " :No such nick");
        return;
    }

    if (channel.hasClient(targetFd)) // Проверяем не находится ли пользователь уже в канале
    {
        sendToClient(fd, ":server 443 " + nick + " " + channelName + " :is already on channel");
        return;
    }

    channel.addInvited(targetFd); // Добавляем пользователя в список приглашённых

    sendToClient(targetFd,
        ":" + _clients[fd]->getNickname() +
        " INVITE " + nick + " " + channelName); // Отправляем пользователю приглашение

    sendToClient(fd,
        ":server 341 " + nick + " " + channelName); // Подтверждаем отправителю что приглашение отправлено
}