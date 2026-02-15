/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:45:36 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 19:59:30 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

const std::string&  Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& new_value) {
    type = new_value;
}

Weapon::~Weapon() {
    std::cout << type << " destroyed\n";
}