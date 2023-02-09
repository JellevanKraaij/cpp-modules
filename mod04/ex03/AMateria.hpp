#pragma once

#include <string>

class ICharacter;

class AMateria {
   public:
    AMateria();
    AMateria(const std::string &type);
    AMateria(const AMateria &other);
    virtual ~AMateria();

    const std::string &getType() const;
    virtual AMateria *clone() = 0;
    virtual void use(ICharacter &target);

   protected:
    AMateria &operator=(const AMateria &other);
    std::string _type;
};
