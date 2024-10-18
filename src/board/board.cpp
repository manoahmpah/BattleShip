//
// Created by MPAH on 14/10/2024.
//
#include <iostream>
#include <string>
#include "boards.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

void Board::createBoard() {
    board = new Cell *[size];
    for (int i = 0; i < size; i++) {
        board[i] = new Cell[size];
    }
}

Board::Board(int Size) {
    size = Size;
    numberShipsSunken = 0;
    createBoard();
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (int i = 0; i < board.size; i++) {

        os << char(65+i) << "  ║";
        for (int j = 0; j < board.size; j++) {
            if (board.board[i][j].isHide) {
                os << " . ";
            } else if (board.board[i][j].ship != nullptr) {
                if (board.board[i][j].ship->isSunk) {
                    os << RED << " X " << RESET;
                } else if (board.board[i][j].ship->isHit) {
                    os << "🔥 ";
                } else {
                    os << " " << board.board[i][j].ship->name[0] << " ";
                }
            } else {
                os << "💧 ";
            }
        }
        os << std::endl;  // Nouvelle ligne à la fin de chaque ligne du tableau
    }
    os << "   ╚═════════════════════════════" << std::endl;
    os << "    1  2  3  4  5  6  7  8  9  10" << std::endl;
    return os;
}


bool Board::errorPosition(int x, int y, const Ship &ship) const {
    if (x < 0 || x > size || y < 0 || y > size) {
        std::cout << "Position out of range" << std::endl;
        return false;
    }

    if (ship.isHorizontal && y + ship.size > size) {
        std::cout << "Ship out of range" << std::endl;
        return false;
    }

    for (int i = 0; i < ship.size; i++) {
        if (ship.isHorizontal && !board[x][y + i].isHide) {
            std::cout << "Position already occupied" << std::endl;
            return false;
        }

        if (!ship.isHorizontal && !board[x + i][y].isHide) {
            std::cout << "Position already occupied" << std::endl;
            return false;
        }
    }
    return true;
}

bool Board::addShip(int x, int y, Ship &ship) const {

    if (!errorPosition(x, y, ship)) {
        return false;
    }


    if (ship.isHorizontal && board[x][y].isHide) {
        for(int i = 0; i < ship.size; i++) {
            board[x][y + i].isHide = false;
            board[x][y + i].ship = &ship;

        }

    } else if (!ship.isHorizontal && board[x][y].isHide) {
        for (int i = 0; i < ship.size; i++) {
            board[x + i][y].isHide = false;
            board[x + i][y].ship = &ship;
        }
    }
    return true;
}

void Board::hitCell(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        std::cout << "Position out of range" << std::endl;
        return;
    }
    if (board[x][y].ship == nullptr) {
        std::cout << "======= Miss =======" << std::endl;
        std::cout << board[x][y].stat << std::endl;
        board[x][y].stat = "o";
        board[x][y].isHide = false;
    }else if(board[x][y].ship->size == 1 && board[x][y].stat != "x") {
        board[x][y].ship->isSunk = true;
        numberShipsSunken++;
        board[x][y].stat = "X";
        board[x][y].ship->size--;
        board[x][y].isHide = false;
    }else if (board[x][y].ship != nullptr && board[x][y].stat != "x") {
        board[x][y].ship->isHit = true;
        board[x][y].stat = "x";
        board[x][y].ship->size--;
        board[x][y].isHide = false;

    }
}


void Board::placeAutomatically(std::list<Ship> &Ships) const {
    std::list x = {0, 1, 5, 6, 9};
    std::pmr::list y = {0, 0, 5, 1, 0};

    const int size = Ships.size();
    for (int i = 0; i < size; i++) {
        auto ship = Ships.begin();

        auto X = x.begin();
        std::advance(X, i);

        auto Y = y.begin();
        std::advance(Y, i);

        std::advance(ship, i);

        addShip(*X, *Y, *ship);
    }

}

void Board::hiddenBoard() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j].isHide = true;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}
