#ifndef FLEET_H
#define FLEET_H
#include <vector>
#include "Ship.h"


class Fleet {
    public:
        void addShip(const std::string &name, bool isHorizontal, int size, bool isSunk);

        /* =========== Getter =========== */
        [[nodiscard]] std::vector<Ship> getShips() const;
        Ship *getShip(int index);
        [[nodiscard]] size_t getSize() const;

        /* =========== Setter =========== */
        void setShips(const std::vector<Ship> &ships);

    private:
        std::vector<Ship> _ships = {
            Ship(1, "Aircraft carrier", true, 5, false),
            Ship(2, "Battleship", false, 4, false),
            Ship(3, "Cruiser", true, 3, false),
            Ship(4, "Submarine", true, 3, false),
            Ship(5, "Destroyer", true, 2, false)
        };
};



#endif //FLEET_H
