#pragma once
#include "Board.h"
#include "Fleet.h"
#ifndef PLAYER_H
#define PLAYER_H



class Player {
public:
        explicit Player(std::string Name);

        /* =========== Methods ========== */
        void displayBoard() const;
        void hideBoard() const;
        void placeAuto();
        void createBoard();
        void hideBoard();
        void placeShips();
        void hitOpponentCell(int x, int y);
        void hitCell(int x, int y);
        void autoHitCell();

        /* =========== Setter =========== */
        void setAutoPlay(bool autoPlay);

        /* =========== Getter =========== */
        Board& getBoard();
        Fleet& getFleet();
        [[nodiscard]] bool getAutoPlay() const;
        [[nodiscard]] int getNumberShipsSunken() const;
        [[nodiscard]] size_t getFleetSize() const;
        [[nodiscard]] std::string getName() const;

private:
        bool placeShip(int x, int y, Ship &ship) const;

        /* =========== Attributes =========== */
        std::string _name;
        Board _playerBoard;
        bool _autoPlay = false;
        Fleet _playerFleet;
};



#endif
