/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:46:22 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 20:37:38 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
# include "Weapon.hpp"

class   HumanB {
    private:
        std::string     name;
        Weapon*          type;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& type);
        void attack();
        ~HumanB();
};

#endif