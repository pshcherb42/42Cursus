/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:46:33 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 20:38:20 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), type(NULL) {}

void HumanB::setWeapon(Weapon& type) {
    this->type = &type;
}

void HumanB::attack() {
    if (type)
    {
        std::cout << name << " attacks with their " << type->getType() << std::endl;
    } else
    {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
    
}

HumanB::~HumanB() {
    std::cout << name << " destroyed\n";
}