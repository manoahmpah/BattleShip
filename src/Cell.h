#ifndef CELL_H
#define CELL_H

#include <string>
#include "Ship.h"


class Cell {
    public:
        Cell();

        /* =========== Getter =========== */
        [[nodiscard]] std::string getStat() const;
        [[nodiscard]] bool getIsHidden() const;
        [[nodiscard]] Ship *getShip() const;

        /* =========== Setter =========== */
        void setStat(const std::string_view &stat);
        void setIsHidden(bool isHidden);
        void setShip(Ship *ship);

    private:
        std::string _stat;
        bool _isHidden;
        Ship *_ship;
};



#endif //CELL_H
