#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap Guiliermo("Guiliermo");
    ScavTrap Nolan("Nolan");
    FragTrap Coppola("Coppola");

    Guiliermo.attack(Nolan.getName());
    Nolan.takeDamage(Guiliermo.getAttackDamage());

    Nolan.beRepaired(3);
    Nolan.attack(Guiliermo.getName());
    Guiliermo.takeDamage(Nolan.getAttackDamage());
    Guiliermo.beRepaired(4);
    Nolan.guardGate();
    Coppola.attack(Nolan.getName());
    Nolan.takeDamage(Coppola.getAttackDamage());
    Nolan.beRepaired(20);
    Coppola.highFivesGuys();

    return (0);
}