#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string const& name);
        FragTrap(const FragTrap& copy);
        FragTrap &operator=(const FragTrap &other);
        void highFivesGuys(void);
        ~FragTrap();
};

#endif