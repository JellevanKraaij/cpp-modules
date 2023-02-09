#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
   public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    ~Character();

    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    Character &operator=(const Character &other);

   private:
    std::string _name;
    static const int _maxMaterias = 4;
    AMateria *_materias[_maxMaterias];
};
