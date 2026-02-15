/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:19:29 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 17:55:34 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;
public:
    Zombie(std::string name);
    void announce( void );
    ~Zombie();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif