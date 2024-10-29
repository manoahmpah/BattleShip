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

        /* =========== Methods ========== */
        void displayBoard() const;
        void hideBoard() const;
        void placeAuto();
        void createBoard();
        void hideBoard();
        void placeShips();
        void gameMode();
        void hitCell(int x, int y);
        void autoHitCell();
        void displayOpponentBoard() const;

        /* =========== Setter =========== */
        void setOpponentBoard(const Board &board);
        void setAutoPlay(bool autoPlay);

        /* =========== Getter =========== */
        Board& getBoard();
        Fleet& getFleet();
        [[nodiscard]] bool getAutoPlay() const;
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] Board getOpponentBoard() const;

private:
        bool placeShip(int x, int y, Ship &ship) const;

        /* =========== Attributes =========== */
        std::string _name;
        Board _playerBoard;
        bool _autoPlay = false;
        Board _opponentBoard;
        Fleet _playerFleet;
};



#endif //PLAYER_H
