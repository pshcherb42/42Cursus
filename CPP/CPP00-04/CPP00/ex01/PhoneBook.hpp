/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:16:07 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/03 15:10:39 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <limits>
# include "Contact.hpp"

class   PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		
	public:
		PhoneBook() : contactCount(0) {}
		~PhoneBook() {};
	
		void	addContact(const Contact& contact)
		{
			static int 	oldestIndex = 0;
			if (contactCount < 8)
			{
				contacts[contactCount] = contact;
				contactCount++;
			}
			else
			{
				contacts[oldestIndex] = contact;
				oldestIndex = (oldestIndex + 1) % 8;
			}
		}
		std::string truncate(const std::string& text, int width) const {
    		if (text.length() > static_cast<std::string::size_type>(width)) {
        		return text.substr(0, width - 1) + ".";
    		}
    		return text;
		}
		
		void	searchContacts() const {
			const int 	columnWidth = 10;
			
			std::cout << std::setw(columnWidth) << std::right << "Index" << "   |   ";
			std::cout << std::setw(columnWidth) << std::right << "First Name" << "   |   "; 
			std::cout << std::setw(columnWidth) << std::right << "Last Name" << "   |   ";
			std::cout << std::setw(columnWidth) << std::right << "Nick Name" << std::endl;
			
			for (int i = 0; i < contactCount; i++) {
				std::cout.width(10);
				std::cout << std::setw(columnWidth) << std::right << i + 1 << "   |   ";
				std::cout << std::setw(columnWidth) << std::right << truncate(contacts[i].getFirstName(), columnWidth) << "   |   ";
				std::cout << std::setw(columnWidth) << std::right << truncate(contacts[i].getLastName(), columnWidth) << "   |   ";
				std::cout << std::setw(columnWidth) << std::right << truncate(contacts[i].getNickName(), columnWidth) << std::endl;
			}
		}
		
		std::string	display(const std::string& text) const {
			return text;
		}
		
		void	displayContact() const {
			std::cout << "Type in the index of the entry to display.\n";
			int	i;
			
			if (!(std::cin >> i)) {
				if (std::cin.eof()) {
            		std::cout << "EOF detected. Exiting program.\n";
            		exit(0);
        		} else {
        			std::cin.clear();
        			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        			std::cout << "Invalid input. Please enter a valid index.\n";
        			return ;
    			}
			}
			
			if (i < 1 || i >= (contactCount + 1)) {
        		std::cout << "Invalid index. Please try again.\n";
        		return ;
    		}
				
			std::cout << "First Name: " << display(contacts[i - 1].getFirstName()) << "\n";
			std::cout << "Last Name: " << display(contacts[i - 1].getLastName()) << "\n";
			std::cout << "Nick Name: " << display(contacts[i - 1].getNickName()) << "\n";
			std::cout << "Phone Number: " << display(contacts[i - 1].getPhoneNumber()) << "\n";
			std::cout << "Darkest Secret: " << display(contacts[i - 1].getDarkestSecret()) << "\n";
		}
};

#endif