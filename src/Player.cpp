//
// Created by MPAH on 18/10/2024.
//

#include "Player.h"
#include "Board.h"
#include "Fleet.h"
#include <iostream>
#include <unistd.h>

#include "Art.h"
#include "UX.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

Player::Player(const std::string &Name)
    : playerBoard(10)
    , playerFleet()
{
    name = Name;
    autoPlay = false;
}

void Player::displayBoard() const {
    std::cout << playerBoard << std::endl;
}

bool Player::placeShip(const int x, const int y, Ship &ship) const {
    if (!playerBoard.errorPosition(x, y, ship)) {
        return false;
    }

    if (ship.isHorizontal && playerBoard.board[x][y].isHidden) {
        for(int i = 0; i < ship.size; i++) {
            playerBoard.board[x][y + i].isHidden = false;
            playerBoard.board[x][y + i].ship = &ship;
        }

    } else if (!ship.isHorizontal && playerBoard.board[x][y].isHidden) {
        for (int i = 0; i < ship.size; i++) {
            playerBoard.board[x + i][y].isHidden = false;
            playerBoard.board[x + i][y].ship = &ship;
        }
    }

    return true;
}

void Player::autoPlaceShips() {
    int x; int y;
    int chosenShip;

    system("cls");
    std::cout << " ========= " << name << " =========" << std::endl;
    std::cout << playerBoard << std::endl;
    int numberShipsPosed = 0;
    while (numberShipsPosed < playerFleet.Ships.size()) {
        numberShipsPosed++;
        UX::questionAddShip(chosenShip, playerFleet.Ships);

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > playerFleet.Ships.size()) {
            std::cout << "Invalid ship" << std::endl;
            continue;
        }

        UX::questionPosition(x, y);

        auto ship = playerFleet.Ships.begin();
        std::advance(ship, chosenShip - 1);
        if (ship->isPosed) {
            system("cls");
            std::cout << std::endl;
            std::cout << RED << "Ship already posed" << RESET << std::endl;
            std::cout << std::endl;
            std::cout << playerBoard << std::endl;
            std::cout << std::endl;
            continue;
        }
        ship->isPosed = true;

        if (!placeShip(x - 1, y - 1, *ship)) {
            std::cout << playerBoard << std::endl;
            continue;
        }

        system("cls");
        std::cout << " ========= " << name << " =========" << std::endl;
        std::cout << playerBoard << std::endl;
    }
}

void Player::gameMode()  {
    std::cout << "Starting Battle Ship Game" << std::endl;
    int gameMode;
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║            Choose a mode              ║\n";
    std::cout << "╠═══════════════════════════════════════╣\n";
    std::cout << "║    1 - Solo mode                      ║\n";
    std::cout << "║    2 - 2 Players mode                 ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n";
    std::cout << "> ";
    std::cin >> gameMode;
    system("cls");
    switch (gameMode) {
        case 1: {
            // Player player1("Maxime");
            // Player player2("Cédric");
            break;
        }
        case 2: {

            break;
        }
        default: {
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }
    system("cls");
    std::cout << " ======= All ships placed =======" << std::endl;
    std::cout << std::endl;
    playerBoard.hiddenBoard();
    std::cout << playerBoard << std::endl;

    while (playerBoard.numberShipsSunken < playerFleet.Ships.size()) {
        int x; int y;
        UX::questionPosition(x, y);
        hitCell(x - 1, y - 1);
        system("cls");
        std::cout << playerBoard << std::endl;
    }
    Art::gameOver();
    sleep(3);
}

void Player::hitCell(int x, int y) {
    if (x < 0 || x >= playerBoard.size || y < 0 || y >= playerBoard.size) {
        std::cout << "Position out of range" << std::endl;
        return;
    }
    if (playerBoard.board[x][y].ship == nullptr) {
        std::cout << "======= Miss =======" << std::endl;
        std::cout << playerBoard.board[x][y].stat << std::endl;
        playerBoard.board[x][y].stat = "o";
        playerBoard.board[x][y].isHidden = false;
    }else if(playerBoard.board[x][y].ship->size == 1 && playerBoard.board[x][y].stat != "x") {
        playerBoard.board[x][y].ship->isSunk = true;
        playerBoard.numberShipsSunken++;
        playerBoard.board[x][y].stat = "X";
        playerBoard.board[x][y].ship->size--;
        playerBoard.board[x][y].isHidden = false;
    }else if (playerBoard.board[x][y].ship != nullptr && playerBoard.board[x][y].stat != "x") {
        playerBoard.board[x][y].ship->isHit = true;
        playerBoard.board[x][y].stat = "x";
        playerBoard.board[x][y].ship->size--;
        playerBoard.board[x][y].isHidden = false;

    }
}