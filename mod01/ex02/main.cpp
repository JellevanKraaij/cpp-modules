#include <iostream>
#include <string>

int main(void) {
    std::string string = "HI THIS IS BRAIN";

    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory adress of string variable = " << &string << std::endl;
    std::cout << "Memory adress held by PTR = " << stringPTR << std::endl;
    std::cout << "Memory adress held by REF = " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string variable = " << string << std::endl;
    std::cout << "Value of string via PTR = " << *stringPTR << std::endl;
    std::cout << "Value of string via REF = " << stringREF << std::endl;
}
