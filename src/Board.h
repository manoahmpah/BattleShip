#ifndef BOARDS_H
#define BOARDS_H

#include "Cell.h"
#include "Fleet.h"
#include "Ship.h"
#include "Color.h"

class Board {
    public:

        /* =========== constructor & destructor =========== */
        explicit Board(int Size);
        ~Board();

        /* =========== Methods =========== */
        void placeAutomatically(Fleet &fleet) const;
        [[nodiscard]] bool errorPosition(int x, int y, const Ship &ship) const;
        bool addShip(int x, int y, Ship &ship) const;
        void createBoard();
        void hitCell(int x, int y);
        void hideBoard() const;
        void addNumberShipsSunken();
        void decrementShipSize(int x, int y) const;

        /* =========== Getter =========== */
        [[nodiscard]] int getNumberShipsSunken() const;
        [[nodiscard]] Cell **getBoard() const;
        [[nodiscard]] int getSize() const;
        [[nodiscard]] std::string getStat(int x, int y) const;
        [[nodiscard]] Ship *getShip(int x, int y) const;
        [[nodiscard]] int getShipSize(int x, int y) const;
        [[nodiscard]] bool getCellHidden(int x, int y) const;
        [[nodiscard]] bool getIsShipSunk(int x, int y) const;
        [[nodiscard]] char getShipFirstLetter(int x, int y) const;
        [[nodiscard]] bool getIsShipHit(int x, int y) const;


        /* =========== Setter =========== */
        void setShip(int x, int y, Ship &ship) const;
        void setCellHidden(int x, int y, bool isHidden) const;
        void setCellStat(int x, int y, const std::string &stat) const;
        void setCellHit(int x, int y, bool isHit) const;
        void setCellSunken(int x, int y, bool isSunk) const;

    private:
        Cell **_board{};
        int _numberShipsSunken = 0;
        int _size;

        /* =========== Overload =========== */
        friend std::ostream &operator<<(std::ostream &os, const Board &board);

};





#endif
