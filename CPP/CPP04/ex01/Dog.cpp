#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called." << std::endl;
};

Dog::Dog(std::string _type) {
    type = _type;
    std::cout << "Dog parameterized constructor called." << std::endl;
};

Dog::Dog(const Dog& other) : Animal(other){
    brain = new Brain;
    *brain = *(other.brain);
    std::cout << "Dog copy constructor called." << std::endl;
};

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain;
        *brain = *(other.brain);
    }
    std::cout << "Dog assignment operator called." << std::endl;
    return *this;
};

void Dog::makeSound() const{
    std::cout << "Wuf!" << std::endl;
};

void Dog::show_data() {
    std::cout << "Brain object pointing to = " << brain << std::endl;
};

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}