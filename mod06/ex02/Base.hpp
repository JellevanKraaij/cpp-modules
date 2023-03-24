#pragma once

class Base {
   public:
    virtual ~Base();
};

Base *generate(void);
void indentify(Base *p);
void indentify(Base &p);
