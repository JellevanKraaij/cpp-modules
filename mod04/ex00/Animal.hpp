#pragma once

#include <iostream>
#include <string>

class Animal {
   public:
    Animal();
    Animal(const Animal &other);
    ~Animal();

    Animal &operator=(const Animal &other);

   protected:
	Animal(const std::string &type);
    std::string type;
};
