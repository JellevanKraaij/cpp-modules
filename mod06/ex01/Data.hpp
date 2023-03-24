#pragma once
#include <string>

class Data {
   public:
    Data();
    Data(const std::string& message);
    Data(const Data& other);
    ~Data();

    Data& operator=(const Data& other);
    void printMessage() const;

   private:
    std::string _message;
};
