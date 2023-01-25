#pragma once

#include "ClapTrap.hpp"

class ScarvTrap : public ClapTrap {
   public:
    ScarvTrap();
    ScarvTrap(const std::string name);
    ScarvTrap(const ScarvTrap &other);
    ~ScarvTrap();

    ScarvTrap &operator=(const ScarvTrap &other);

    void attack(const std::string &target);

    void guardGate() const;
};
