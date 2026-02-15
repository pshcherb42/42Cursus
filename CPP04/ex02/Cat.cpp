#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    Cazuchi = new Brain();
    std::cout << "Cat default constructor called." << std::endl;
};

Cat::Cat(std::string _type) {
    type = _type;
    Cazuchi = new Brain();
    std::cout << "Cat parameterized constructor called." << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other) {
    Cazuchi = new Brain;
    *Cazuchi = *(other.Cazuchi);
    std::cout << "Cat copy constructor called." << std::endl;
};

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete Cazuchi;
        Cazuchi = new Brain;
        *Cazuchi = *(other.Cazuchi);
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
};

void Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
};

void Cat::show_data() {
    std::cout << "Brain object pointing to = " << Cazuchi << std::endl;
};

Cat::~Cat() {
    delete Cazuchi;
    std::cout << "Cat destructor called." << std::endl;
}