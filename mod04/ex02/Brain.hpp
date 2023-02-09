#pragma once
#include <iostream>
#include <string>

class Brain {
   public:
    Brain();
    Brain(const Brain &other);
    ~Brain();

    Brain &operator=(const Brain &other);

    std::string ideas[100];
};
