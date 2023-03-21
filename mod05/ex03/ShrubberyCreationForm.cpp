#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this == &other)
        return (*this);
    AForm::operator=(other);
    return (*this);
}

static char forest[] = {
    "               ,@@@@@@@,\n"
    "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
    "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
    "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
    "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
    "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
    "       |o|        | |         | |\n"
    "       |.|        | |         | |\n"
    "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"};

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
    AForm::execute(bureaucrat);
    std::ofstream outfile(getName() + "_shrubbery", std::ios::app);
    outfile << forest << std::endl;
}

AForm *ShrubberyCreationForm::create(const std::string &name) {
    return new ShrubberyCreationForm(name);
}