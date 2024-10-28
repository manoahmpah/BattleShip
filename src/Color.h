
#ifndef COLOR_H
#define COLOR_H
#include <string>

enum class Color {
    RESET,
    RED
};

std::string getColorCode(Color color);

#endif
