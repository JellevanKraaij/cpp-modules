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

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    bool operator<(const Fixed &rhs) const;
    bool operator>(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;

    static const Fixed &max(const Fixed &f1, const Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static Fixed &min(Fixed &f1, Fixed &f2);

    static Fixed abs(const Fixed &f1);

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
