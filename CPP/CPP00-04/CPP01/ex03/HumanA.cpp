/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:46:10 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 19:58:16 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA(std::string name, Weapon type) {
//     this->name = name;
//     this->type = type;
// }

HumanA::HumanA(std::string name, Weapon& type) : name(name), type(type) {}

void HumanA::attack() {
    std::cout << name << " attacks with their " << type.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << name << " destroyed\n";
}