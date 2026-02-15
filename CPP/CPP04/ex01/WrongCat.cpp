#include "WrongCat.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat default constructor called." << std::endl;
};

WrongCat::WrongCat(std::string const& type) {
    _type = type;
    std::cout << "WrongCat parameterized constructor called." << std::endl;
};

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called." << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat assignment operator called." << std::endl;
    return *this;
};

void WrongCat::makeSound() const{
    std::cout << "WrongCat sound!" << std::endl;
};

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}