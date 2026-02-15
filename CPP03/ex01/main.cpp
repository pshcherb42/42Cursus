#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap Guiliermo("Guiliermo");
    ScavTrap Nolan("Nolan");

    Guiliermo.attack(Nolan.getName());
    Nolan.takeDamage(Guiliermo.getAttackDamage());

    Nolan.beRepaired(3);
    Nolan.attack(Guiliermo.getName());
    Guiliermo.takeDamage(Nolan.getAttackDamage());
    Guiliermo.beRepaired(4);
    Nolan.guardGate();

    return (0);
}