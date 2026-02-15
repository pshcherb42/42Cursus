/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:29:51 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/01 18:19:12 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    std::string command;
	PhoneBook	phoneBook;

    (void)argc;
    (void)argv;

    while (true) {
        std::cout << "Write one of the following commands: ADD, SEARCH, EXIT\n";
        std::cin >> command;
		if (std::cin.eof()) {
			std::cout << "EOF detected. Exiting program.\n";
            exit(0);
		}
        if (command == "ADD") {
			std::string    firstName, lastName, nickName, phoneNumber, darkestSecret;
			std::cout << "First Name: ";
			std::cin >> firstName;
			std::cout << "Last Name: ";
			std::cin >> lastName;
			std::cout << "Nick Name: ";
			std::cin >> nickName;
			std::cout << "Phone Number: ";
			std::cin >> phoneNumber;
			std::cout << "Darkest Secret: ";
			std::cin >> darkestSecret;
            Contact myContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
			phoneBook.addContact(myContact);
        } else if (command == "SEARCH") {
			phoneBook.searchContacts();
			phoneBook.displayContact();
        } else if (command == "EXIT") {
            std::cout << "Exiting the program.\n";
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
    return 0;
}