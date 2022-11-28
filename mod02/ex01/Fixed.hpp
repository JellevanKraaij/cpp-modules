#pragma once

#include <ostream>

class Fixed {
   public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
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

    static int _convertToRaw(const int num);
    static int _convertToRaw(const float num);
    static int _convertToInt(const int raw);
    static float _convertToFloat(const int raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &cl);
