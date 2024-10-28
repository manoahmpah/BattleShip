//
// Created by MPAH on 18/10/2024.
//
#include "Board.h"
#include "Fleet.h"
#ifndef PLAYER_H
#define PLAYER_H



class Player {
public:
        explicit Player(std::string Name);
        void displayBoard() const;
        Player& operator=(const Player &player);
        void PlaceShips();
        void gameMode();
        void setOpponentBoard(const Board &board);
        Board& getBoard();
        Fleet& getFleet();
        void hitCell(int x, int y);
        [[nodiscard]] std::string getName() const;



private:
        std::string name;
        bool placeShip(int x, int y, Ship &ship) const;
        Board playerBoard;
        bool autoPlay = false;
        Board opponentBoard;
        Fleet playerFleet;
};



#endif //PLAYER_H
