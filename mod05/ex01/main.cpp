#include <iostream>

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat validRights("ValidRights", 1);
    Bureaucrat invalidRights("InvalidRights", 2);

    std::cout << validRights << std::endl;
    std::cout << invalidRights << std::endl;

    Form form("validForm", 1, 1);

    std::cout << form << std::endl;

    std::cout << std::endl;

    invalidRights.signForm(form);
    validRights.signForm(form);

    std::cout << std::endl;

    std::cout << "create invalid form" << std::endl;
    try {
        Form test("test", 0, 151);
    } catch (const std::exception& e) {
        std::cout << "caught exception, message: " << e.what() << std::endl;
    }
}
