//
// Created by MPAH on 18/10/2024.
//
#include "Board.h"
#include "Fleet.h"
#ifndef PLAYER_H
#define PLAYER_H



class Player {
public:
        Player(const std::string &name);
        void displayBoard() const;
        void autoPlaceShips();
        void gameMode();

private:
        std::string name;
        bool placeShip(int x, int y, Ship &ship) const;
        void hitCell(int x, int y);
        Board playerBoard;
        Fleet playerFleet;
        bool autoPlay = false;
};



#endif //PLAYER_H
