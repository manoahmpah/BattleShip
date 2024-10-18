//
// Created by MPAH on 14/10/2024.
//
#include <iostream>
#include <string>
#include <unistd.h>
#include "Board.h"
#include "UX.h"
#include "Art.h"
#include "Player.h"

using namespace std;

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
            if (board.board[i][j].isHidden) {
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
        if (ship.isHorizontal && !board[x][y + i].isHidden) {
            std::cout << "Position already occupied" << std::endl;
            return false;
        }

        if (!ship.isHorizontal && !board[x + i][y].isHidden) {
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


    if (ship.isHorizontal && board[x][y].isHidden) {
        for(int i = 0; i < ship.size; i++) {
            board[x][y + i].isHidden = false;
            board[x][y + i].ship = &ship;

        }

    } else if (!ship.isHorizontal && board[x][y].isHidden) {
        for (int i = 0; i < ship.size; i++) {
            board[x + i][y].isHidden = false;
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
        board[x][y].isHidden = false;
    }else if(board[x][y].ship->size == 1 && board[x][y].stat != "x") {
        board[x][y].ship->isSunk = true;
        numberShipsSunken++;
        board[x][y].stat = "X";
        board[x][y].ship->size--;
        board[x][y].isHidden = false;
    }else if (board[x][y].ship != nullptr && board[x][y].stat != "x") {
        board[x][y].ship->isHit = true;
        board[x][y].stat = "x";
        board[x][y].ship->size--;
        board[x][y].isHidden = false;

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
            board[i][j].isHidden = true;
        }
    }
}

void Board::placeManually(std::list<Ship> Ships) const {
    int x; int y;
    int chosenShip;

    cout << *this << endl;
    int numberShipsPosed = 0;
    while (numberShipsPosed < Ships.size()) {
        numberShipsPosed++;
        UX::questionAddShip(chosenShip, Ships);

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > Ships.size()) {
            cout << "Invalid ship" << endl;
            continue;
        }

        UX::questionPosition(x, y);

        auto ship = Ships.begin();
        std::advance(ship, chosenShip - 1);
        if (ship->isPosed) {
            system("cls");
            cout << endl;
            cout << RED << "Ship already posed" << RESET << endl;
            cout << endl;
            cout << *this << endl;
            cout << endl;
            continue;
        }
        ship->isPosed = true;

        if (!addShip(x - 1, y - 1, *ship)) {
            cout << *this << endl;
            continue;
        }

        system("cls");
        cout << *this << endl;
    }

}

void Board::play(std::list<Ship> Ships)  {
    cout << "Starting Battle Ship Game" << endl;
    int gameMode;
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║            Choose a mode              ║\n";
    cout << "╠═══════════════════════════════════════╣\n";
    cout << "║    1 - Solo mode                      ║\n";
    cout << "║    2 - 2 Players mode                 ║\n";
    cout << "╚═══════════════════════════════════════╝\n";
    cout << "> ";
    cin >> gameMode;
    system("cls");
    switch (gameMode) {
        case 1: {
            placeAutomatically(Ships);
            break;
        }
        case 2: {
            placeManually(Ships);
            break;
        }
        default: {
            cout << "Invalid option. Please try again." << endl;
            play(Ships);
            break;
        }
    }
    system("cls");
    cout << " ======= All ships placed =======" << endl;
    cout << endl;
    hiddenBoard();
    cout << *this << endl;

    while (numberShipsSunken < Ships.size()) {
        int x; int y;
        UX::questionPosition(x, y);
        hitCell(x - 1, y - 1);
        system("cls");
        cout << *this << endl;
    }
    Art::gameOver();
    sleep(3);
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}
