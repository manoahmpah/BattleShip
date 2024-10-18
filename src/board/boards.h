//
// Created by MPAH on 14/10/2024.
//

#ifndef BOARDS_H
#define BOARDS_H
#include <list>

#include "../Cell/Cell.h"
#include "../Ship/Ship.h"

class Board {
    public:
        friend std::ostream& operator<<(std::ostream& os, const Board& board);
        Cell **board{};
        int numberShipsSunken;
        int size;
        void createBoard();
        bool addShip(int x, int y, Ship &ship) const;
        void placeAutomatically(std::list<Ship> &Ships) const;
        void hitCell(int x, int y);
        void hiddenBoard() const;
        ~Board();
        Board(int Size);


    private:
        bool errorPosition(int x, int y, const Ship &ship) const;


};





#endif //BOARDS_H
