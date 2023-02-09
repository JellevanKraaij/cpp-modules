#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);

   private:
    static const int _maxMaterias = 4;
    AMateria *_learnedMaterias[_maxMaterias];
};
