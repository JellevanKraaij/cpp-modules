#pragma once

#include <string>

class ClapTrap {
   public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &other);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   protected:
    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _damage;
    ClapTrap(const std::string &name, unsigned int health, unsigned int energy, unsigned int damage);
};
