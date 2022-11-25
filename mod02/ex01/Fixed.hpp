#pragma once

#include <ostream>

class Fixed {
   public:
    Fixed();
    Fixed(const int num);
    Fixed(const Fixed &copy);
    ~Fixed();

    Fixed &operator=(const Fixed &assign);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    int toInt(void) const;
    float toFloat(void) const;

   private:
    static const int _fractBits = 8;
    int _value;

    static int _convertToRaw(const int val);
    static int _convertToInt(const int val);
};

std::ostream& operator<<(std::ostream &os, const Fixed &cl);
