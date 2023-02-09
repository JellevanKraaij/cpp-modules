#pragma once

#include <iostream>
#include <string>

class AAnimal {
   public:
    AAnimal();
    AAnimal(const AAnimal &other);
    virtual ~AAnimal();

    std::string getType() const;
    virtual void makeSound() const = 0;

   protected:
    AAnimal &operator=(const AAnimal &other);
    AAnimal(const std::string &type);
    std::string type;
};
