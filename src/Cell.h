//
// Created by MPAH on 15/10/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>
#include "Ship.h"


class Cell {
public:
    std::string stat;
    bool isHidden;
    Ship *ship;
    Cell();
};



#endif //CELL_H
