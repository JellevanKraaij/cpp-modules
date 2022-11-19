#pragma once

#include <string>

class Zombie {
   private:
    std::string _name;
    void _printMessage(const std::string &message) const;

   public:
    Zombie(const std::string &name);
    ~Zombie();

    void announce(void);
};
