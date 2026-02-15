#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int _hpoints;
        int _epoints;
        int _damage;
    public:
        ClapTrap();
        ClapTrap(std::string const& name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap &operator=(const ClapTrap &other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // getters
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;

        ~ClapTrap();
};

#endif