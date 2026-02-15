#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* Cazuchi;
    public:
        Cat();
        Cat(std::string _type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        virtual void makeSound() const;
        virtual void show_data();

        virtual ~Cat();
};

#endif