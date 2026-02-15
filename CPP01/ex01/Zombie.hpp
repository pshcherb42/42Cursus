/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:23:44 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 19:48:30 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        void setName(std::string name);
        void announce(void);
        ~Zombie(); // Destructor
};

Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );