#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string const& name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap &operator=(const ScavTrap &other);
        void attack(const std::string& target);
        void guardGate();
        ~ScavTrap();
};
#endif