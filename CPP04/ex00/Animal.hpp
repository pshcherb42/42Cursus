#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string _type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        virtual void makeSound() const; // virtual function for polymorphism
        const std::string getType() const;
        
        virtual ~Animal();
};

#endif