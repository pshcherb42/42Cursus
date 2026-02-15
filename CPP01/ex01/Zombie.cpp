/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:23:04 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 19:33:21 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

void    Zombie::setName(std::string name) {this->name = name; }

void    Zombie::announce(void) {
    std::cout << name << ":BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
    std::cout << name << " killed\n";
}