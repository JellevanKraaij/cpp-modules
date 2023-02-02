#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    {
        std::cout << "---------- Test copy ----------" << std::endl;
        Cat cat;
        Cat cat2;

        std::cout << std::endl;

        cat.getBrain()->ideas[0] = "Hello world!";
        cat.getBrain()->ideas[1] = "Original CAT string";

        cat2 = cat;

        cat2.getBrain()->ideas[1] = "New CAT2 string";

        std::cout << std::endl;

        std::cout << "cat brain [0,1]:" << std::endl;
        std::cout << cat.getBrain()->ideas[0] << std::endl;
        std::cout << cat.getBrain()->ideas[1] << std::endl;
        std::cout << "cat2 brain [0,1]:" << std::endl;
        std::cout << cat2.getBrain()->ideas[0] << std::endl;
        std::cout << cat2.getBrain()->ideas[1] << std::endl;
    }
    {
        std::cout << "---------- Test Construction & Destruction ----------" << std::endl;

        Animal *animals[100];

        for (int i = 0; i < 50; i++)
            animals[i] = new Dog();
        for (int i = 50; i < 100; i++)
            animals[i] = new Cat();

        std::cout << std::endl;

        for (int i = 0; i < 100; i++)
            delete animals[i];
    }
}
