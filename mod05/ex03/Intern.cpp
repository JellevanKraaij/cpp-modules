#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const Intern::CreateLookup Intern::createLookup[createLookupCnt] = {
	{"presidential pardon", PresidentialPardonForm::create},
	{"robotomy request", RobotomyRequestForm::create},
	{"shrubbery creation", PresidentialPardonForm::create},
};

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return(*this);
}

AForm *Intern::makeForm(const std::string &form, const std::string &name)
{
	for (unsigned int i = 0; i < createLookupCnt; i++)
	{
		if (createLookup[i].form == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (createLookup[i].createF(name));
		}
	}
	std::cout << "Intern failed to create unknown " << form << std::endl;
	return (nullptr);
}
