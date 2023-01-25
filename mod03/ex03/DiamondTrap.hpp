#pragma once

#include "FragTrap.hpp"
#include "ScarvTrap.hpp"

class DiamondTrap : public ScarvTrap, public FragTrap {
   public:
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &other);

    void whoAmI() const;

    using ScarvTrap::attack;

   private:
    std::string _name;
};
