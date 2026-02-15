#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* h = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << h->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound(); // will output dog sound!
    meta->makeSound();
    h->makeSound();

    delete meta;
    delete j;
    delete i;
    delete h;

    return 0;
}