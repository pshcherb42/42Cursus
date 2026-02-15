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

        virtual void makeSound() const = 0; // pure virtual function
        virtual void show_data() = 0;
        const std::string getType() const;
        
        virtual ~Animal();
};

#endif