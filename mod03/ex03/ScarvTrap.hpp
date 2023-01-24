#pragma once

#include "ClapTrap.hpp"

class ScarvTrap : virtual public ClapTrap {
   public:
    ScarvTrap(const std::string name);
    ScarvTrap(const ScarvTrap &other);
    ~ScarvTrap();

    ScarvTrap &operator=(const ScarvTrap &other);

    void guardGate() const;

   protected:
    ScarvTrap();
};
