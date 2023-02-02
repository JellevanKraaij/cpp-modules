#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &other);

    std::string getType() const;
    void makeSound() const;

   protected:
    WrongAnimal(const std::string &type);
    std::string type;
};
