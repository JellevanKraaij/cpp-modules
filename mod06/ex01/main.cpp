#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    std::cout << "create data class with message 'Hello world!'\n" << std::endl;
    Data data("Hello world!");

    std::cout << "print message that is inside data class" << std::endl;
    data.printMessage();
    std::cout << std::endl;

    std::cout << "address of data: " << &data << '\n' << std::endl;

    std::cout << "serialize data pointer" << std::endl;

    uintptr_t result = Serializer::serialize(&data);

    std::cout << "serialize result: " << result << '\n' << std::endl;

    std::cout << "deserialize result to data pointer" << std::endl;

    Data *dataptr = Serializer::deserialize(result);
    std::cout << "deserialize address: " << dataptr << '\n' << std::endl;

    std::cout << "print message that is inside data class" << std::endl;
    dataptr->printMessage();
}