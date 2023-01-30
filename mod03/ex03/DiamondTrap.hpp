#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap &other);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &other);

    void whoAmI() const;

    using ScavTrap::attack;

   private:
    std::string _name;
};
