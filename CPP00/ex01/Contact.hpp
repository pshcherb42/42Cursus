/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:37:09 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/03 14:35:53 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <string>

class   Contact
{
	private:
		std::string    firstName;
		std::string    lastName;
		std::string    nickName;
		std::string    phoneNumber;
		std::string    darkestSecret;
	public:
		Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret(""){}
		~Contact() {};
		Contact(std::string fN, std::string lN, std::string nN, std::string pN, std::string dS)
			: firstName(fN), lastName(lN), nickName(nN), phoneNumber(pN), darkestSecret(dS) {}
		
		std::string getFirstName() const { return firstName; }
    	std::string getLastName() const { return lastName; }
    	std::string getNickName() const { return nickName; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getDarkestSecret() const { return darkestSecret; }	
};

#endif