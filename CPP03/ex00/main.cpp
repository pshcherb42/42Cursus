#include "ClapTrap.hpp"

int main() {
    ClapTrap Guiliermo("Guiliermo");
    ClapTrap Nolan("Nolan");

    Guiliermo.attack(Nolan.getName());
    Nolan.takeDamage(Guiliermo.getAttackDamage());

    Nolan.beRepaired(3);
    Guiliermo.attack(Nolan.getName());
    Nolan.takeDamage(Guiliermo.getAttackDamage());

    std::cout << "Total energy points left " << Nolan.getEnergyPoints() << std::endl;
    std::cout << "Total energy points left " << Guiliermo.getEnergyPoints() << std::endl;

    return (0);
}