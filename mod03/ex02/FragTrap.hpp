#pragma once

#include "ClapTrap.hpp"

class FragTrap : ClapTrap {
   public:
    FragTrap(const std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    FragTrap &operator=(const FragTrap &other);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void highFivesGuys() const;
};
