#include <iostream>
#include <string>
#include "Board.h"
#include "UX.h"
#include "Player.h"

using namespace std;

void Board::createBoard() {
    _board = new Cell *[_size];
    for (int i = 0; i < _size; i++) {
        _board[i] = new Cell[_size];
    }
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (int i = 0; i < board._size; i++) {
        os << static_cast<char>(65 + i) << "  ║";
        for (int j = 0; j < board._size; j++) {
            if (board.getCellHidden(i, j)) {
                os << " . ";
            } else if (board.getShip(i, j) != nullptr) {
                if (board.getIsShipSunk(i, j)) {
                    os << getColorCode(Color::RED) << " X " << getColorCode(Color::RESET);
                } else if (board.getIsShipHit(i, j)) {
                    os << "🔥 ";
                } else {
                    os << " " << board.getShipFirstLetter(i, j) << " ";
                }
            } else {
                os << "💧 ";
            }
        }
        os << std::endl;
    }

    int decoration = 0;
    while (decoration < 2) {
        for (int i = 0; i < board._size; i++) {
            if (decoration == 0) {
                os << (i == 0 ? "   ╚══" : "═══");
            } else {
                os << (i == 0 ? "    " : "  ") << (i + 1);
            }
        }
        os << std::endl;
        decoration++;
    }
    return os;
}

Board::Board(const int Size) {
    _size = Size;
    _numberShipsSunken = 0;
    createBoard();
}


bool Board::errorPosition(const int x, const int y, const Ship &ship) const {
    if (x < 0 || x > _size || y < 0 || y > _size) {
        std::cout << "Position out of range" << std::endl;
        return false;
    }

    if (ship.getIsHorizontal() && y + ship.getSize() > _size) {
        std::cout << "Ship out of range" << std::endl;
        return false;
    }

    for (int i = 0; i < ship.getSize(); i++) {
        if (ship.getIsHorizontal() && !_board[x][y + i].getIsHidden()) {
            std::cout << "Position already occupied" << std::endl;
            std::cout << "here" << std::endl;
            return false;
        }

        if (!ship.getIsHorizontal() && !_board[x + i][y].getIsHidden()) {
            std::cout << "Position already occupied" << std::endl;
            std::cout << "here1" << std::endl;
            return false;
        }
    }
    return true;
}

bool Board::addShip(const int x, const int y, Ship &ship) const {

    if (!errorPosition(x, y, ship)) {
        return false;
    }


    if (ship.getIsHorizontal() && _board[x][y].getIsHidden()) {
        for(int i = 0; i < ship.getSize(); i++) {
            _board[x][y + i].setIsHidden(false);
            _board[x][y + i].setShip(&ship);

        }

    } else if (!ship.getIsHorizontal() && _board[x][y].getIsHidden()) {
        for (int i = 0; i < ship.getSize(); i++) {
            _board[x + i][y].setIsHidden(false);
            _board[x + i][y].setShip(&ship);
        }
    }
    return true;
}


void Board::placeAutomatically(Fleet &fleet) const {
    const std::vector x = {0, 1, 5, 6, 9};
    const std::vector y = {0, 0, 5, 1, 0};

    const size_t size = fleet.getSize();
    for (int i = 0; i < size; i++) {
        Ship *ship = fleet.getShip(i);
        addShip(x[i], y[i], *ship);

    }

}

void Board::hideBoard() const {
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            _board[i][j].setIsHidden(true);
        }
    }
}


/* =========== Getter =========== */
int Board::getNumberShipsSunken() const {
    return _numberShipsSunken;
}
Cell **Board::getBoard() const {
    return _board;
}
int Board::getSize() const {
    return _size;
}
std::string Board::getStat(const int x, const int y) const {
    return _board[x][y].getStat();
}
Ship *Board::getShip(const int x, const int y) const {
    return _board[x][y].getShip();
}
int Board::getShipSize(const int x, const int y) const {
    return _board[x][y].getShip()->getSize();
}
bool Board::getCellHidden(const int x, const int y) const {
    return _board[x][y].getIsHidden();
}
bool Board::getIsShipSunk(const int x, const int y) const {
    return _board[x][y].getShip()->getIsSunk();
}

char Board::getShipFirstLetter(const int x, const int y) const {
    return _board[x][y].getShip()->getName()[0];
}
bool Board::getIsShipHit(const int x, const int y) const {
    return _board[x][y].getShip()->getIsHit();
}


/* =========== Setter =========== */
void Board::setShip(const int x, const int y, Ship &ship) const {
    _board[x][y].setShip(&ship);
}
void Board::setCellHidden(const int x, const int y, const bool isHidden) const {
    _board[x][y].setIsHidden(isHidden);
}
void Board::setCellStat(const int x, const int y, const std::string &stat) const {
    _board[x][y].setStat(stat);
}
void Board::setCellHit(const int x, const int y, const bool isHit) const {
    _board[x][y].getShip()->setIsHit(isHit);
}

void Board::setCellSunken(const int x, const int y, const bool isSunk) const {
    _board[x][y].getShip()->setIsSunk(isSunk);
}


void Board::addNumberShipsSunken() {
    _numberShipsSunken++;
}

void Board::decrementShipSize(const int x, const int y) const {
    _board[x][y].getShip()->setSize(_board[x][y].getShip()->getSize() - 1);
}

Board::~Board() {
    for (int i = 0; i < _size; i++) {
        delete[] _board[i];
    }
    delete[] _board;
}
