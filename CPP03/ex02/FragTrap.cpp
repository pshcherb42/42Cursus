#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
};
FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;

};

FragTrap& FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Assignment Operator Called!" << std::endl;
    return (*this);
};

void FragTrap::highFivesGuys(void) {
    std::cout << "Gimme five!" << std::endl;
};

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor Called!" << std::endl;
};