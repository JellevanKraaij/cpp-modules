#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < _maxMaterias; i++)
        _learnedMaterias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    *this = other;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < _maxMaterias; i++) {
        if (_learnedMaterias[i] != nullptr)
            delete _learnedMaterias[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this == &other)
        return (*this);
    for (int i = 0; i < _maxMaterias; i++) {
        if (_learnedMaterias[i] != nullptr) {
            delete _learnedMaterias[i];
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
    for (int i = 0; i < _maxMaterias; i++) {
        if (_learnedMaterias[i] == nullptr) {
            _learnedMaterias[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < _maxMaterias; i++) {
        if (_learnedMaterias[i] != nullptr && _learnedMaterias[i]->getType() == type) {
            return (_learnedMaterias[i]->clone());
        }
    }
    return (nullptr);
}
