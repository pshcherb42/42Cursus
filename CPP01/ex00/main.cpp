/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:21:59 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/04 17:44:22 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main() {

    Zombie* foo = newZombie("Foo");
    foo->announce();
    delete (foo);
    randomChump("Boo");
    return (0);
}