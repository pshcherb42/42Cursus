/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 20:45:25 by pshcherb          #+#    #+#             */
/*   Updated: 2025/07/07 20:33:55 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class   Weapon {
    private:
        std::string     type;
    public:
        Weapon(std::string type);
        const std::string&   getType() const ;
        void    setType(const std::string& new_value);
        ~Weapon();
};

#endif