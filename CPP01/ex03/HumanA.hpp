/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:45:58 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 19:43:04 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
# include "Weapon.hpp"

class   HumanA {
    private:
        std::string     name;
        Weapon&          type;
    public:
        HumanA(std::string name, Weapon& type);
        void attack();
        ~HumanA();
};

#endif