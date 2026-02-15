/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:53:36 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 17:56:48 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce( void ) {
    std::cout << name << ":" << "BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
    std::cout << name << " killed\n";
}