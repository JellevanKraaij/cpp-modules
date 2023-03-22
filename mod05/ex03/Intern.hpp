#pragma once

#include "AForm.hpp"

class Intern {
   public:
    Intern();
    Intern(const Intern &other);
    ~Intern();

    Intern &operator=(const Intern &other);

    AForm *makeForm(const std::string &form, const std::string &name);

   private:
    struct CreateLookup {
        const std::string form;
        AForm *(*createF)(const std::string &name);
    };

    static const unsigned int createLookupCnt = 3;
    static const CreateLookup createLookup[createLookupCnt];
};
