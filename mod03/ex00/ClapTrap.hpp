#pragma once

#include <string>

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &other);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   private:
    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _damage;
};
