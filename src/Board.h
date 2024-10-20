//
// Created by MPAH on 14/10/2024.
//

#ifndef BOARDS_H
#define BOARDS_H
#include <list>

#include "Cell.h"
#include "Ship.h"

class Board {
    public:
        friend std::ostream& operator<<(std::ostream& os, const Board& board);
        Cell **board{};

        int numberShipsSunken;
        int size;

        bool errorPosition(int x, int y, const Ship &ship) const;
        bool addShip(int x, int y, Ship &ship) const;

        void createBoard();
        void placeAutomatically(std::list<Ship> &Ships) const;
        void hitCell(int x, int y);
        void hiddenBoard() const;
        void placeManually(std::list<Ship> Ships) const;
        void play(std::list<Ship> Ships);

        ~Board();

        explicit Board(int Size);

    private:



};





#endif //BOARDS_H
