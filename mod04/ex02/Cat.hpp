#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
   public:
    Cat();
    Cat(const Cat &other);
    ~Cat();

    Cat &operator=(const Cat &other);

    void makeSound() const;

    Brain *getBrain();

   private:
    Brain *_brain;
};
