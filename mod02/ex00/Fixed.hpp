#pragma once

#include <ostream>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(const int raw);

    Fixed &operator=(const Fixed &assign);

   private:
    static const int _fractBits = 8;
    int _value;
};

std::ostream& operator<<(std::ostream &os, const Fixed &cl);
