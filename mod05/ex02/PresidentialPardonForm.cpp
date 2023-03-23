#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
    AForm::execute(bureaucrat);

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
