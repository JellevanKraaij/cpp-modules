#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    {
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << std::endl;

        std::cout << animal->getType() << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        cat->makeSound();  // will output the cat sound!
        dog->makeSound();
        animal->makeSound();

        std::cout << std::endl;

        delete animal;
        delete dog;
        delete cat;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        const WrongAnimal* animal = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();

        std::cout << std::endl;

        std::cout << animal->getType() << std::endl;
        std::cout << cat->getType() << std::endl;
        cat->makeSound();  // will not output the cat sound!
        animal->makeSound();

        std::cout << std::endl;

        delete animal;
        delete cat;
    }
}
