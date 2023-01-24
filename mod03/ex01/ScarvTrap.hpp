#pragma once

#include "ClapTrap.hpp"

class ScarvTrap : ClapTrap {
   public:
    ScarvTrap(const std::string name);
    ScarvTrap(const ScarvTrap &other);
    ~ScarvTrap();

    ScarvTrap &operator=(const ScarvTrap &other);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void guardGate() const;
};
