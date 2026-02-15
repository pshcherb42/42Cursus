#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << "Animal default constructor called." << std::endl;
};

Animal::Animal(std::string _type) {
    type = _type;
    std::cout << "Animal parameterized constructor called." << std::endl;
};

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called." << std::endl;
};

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        type = other.type;
    std::cout << "Animal assignment operator called." << std::endl;
    return *this;
};

const std::string Animal::getType() const{
    return (type);
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}