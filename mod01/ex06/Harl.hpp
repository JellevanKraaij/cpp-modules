#pragma once

#include <string>

class Harl {
   private:
    static const int _lookup_size = 4;
    static const struct _mapLevels {
        std::string str;
        void (*function)(void);
    } _mapLevels[_lookup_size];

    static void debug(void);
    static void info(void);
    static void warning(void);
    static void error(void);

   public:
    static void complain(std::string level);
};
