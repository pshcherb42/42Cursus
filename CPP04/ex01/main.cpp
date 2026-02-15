#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    int N = 4;
    Animal* arr[N];
    Dog basic;


    {
        Dog tmp = basic;
    }
    // create cats
    for (int i = 0; i < N/2; i++) {
        arr[i] = new Cat();
        arr[i]->makeSound();
        arr[i]->show_data();
    }

    // create dogs
    for (int i = N/2; i < N; i++) {
        arr[i] = new Dog();
        arr[i]->makeSound();
        arr[i]->show_data();
    }



    for (int i = 0; i < N; i++) {
        delete arr[i];
    }

    return 0;
}