#pragma once

#include <string.h>

#include "Weapon.hpp"

class HumanA {
   private:
    const std::string _name;
    const Weapon &_weapon;

   public:
    HumanA(const std::string &name, const Weapon &weapon);
    ~HumanA();

    void attack() const;
};
