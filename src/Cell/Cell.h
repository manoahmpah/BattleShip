//
// Created by MPAH on 15/10/2024.
//

#ifndef CELL_H
#define CELL_H

#include <string>
#include "../Ship/Ship.h"


class Cell {
public:
    Cell();
    std::string stat;
    bool isHide;
    Ship *ship;
};



#endif //CELL_H
