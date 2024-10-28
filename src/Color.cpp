#include "Color.h"

#include <string>

std::string getColorCode(const Color color) {
    switch (color) {
        case Color::RESET: return "\033[0m";
        case Color::RED:   return "\033[31m";
        default:           return "\033[0m";
    }
}