#pragma once

#include <string.h>

#include "Weapon.hpp"

class HumanB {
   private:
    const std::string _name;
    const Weapon *_weapon;

   public:
    HumanB(const std::string &name);
    ~HumanB();

    void attack() const;
    void setWeapon(Weapon &weapon);
};
