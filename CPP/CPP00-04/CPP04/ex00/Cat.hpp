#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(std::string _type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        virtual void makeSound() const;

        ~Cat();
};

#endif