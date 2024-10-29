#include "Game.h"
#include <iostream>

#include "Art.h"
#include "UX.h"

using namespace std;

Game::Game(const Player &player1, const Player &player2): _player1("Maxime"), _player2("Cédric") {
    this->_player1 = player1;
    this->_player2 = player2;
}

void Game::startGame() {
    Art::showLandingPage();
    const int option = isNumber();

    std::cout << std::endl;

    switch (option) {
        case 1:
            system("cls");
        chooseGameMode();
        break;
        case 2:
            Art::showInstructions();
        std::cin.ignore();
        std::cin.get();
        break;
        case 3:
            std::cout << "Goodbye" << std::endl;
        break;
        default:
            Art::invalidOption();
        startGame();
        break;
    }
}

void Game::chooseGameMode() {
    Art::gameMode();
    const int gameMode = isNumber();

    _player1 = Player("Maxime");
    _player2 = Player("Cédric");
    _player1.createBoard();
    _player2.createBoard();

    system("cls");
    switch (gameMode) {
        case 1: {
            _player1.placeAuto();
            _player1.hideBoard();

            _player2.placeShips();
            _player2.setAutoPlay(true);
            _player2.hideBoard();

            gameLoop(_player1, _player2, _playerToPlay);
            Art::gameOver();
            break;
        }
        case 2: {
            _player1.placeShips();
            _player1.hideBoard();

            _player2.placeShips();
            _player2.hideBoard();

            gameLoop(_player1, _player2, _playerToPlay);
            Art::gameOver();
            break;
        }
        case 3: {
            return;
        }
        default: {
            Art::invalidOption();
            chooseGameMode();
            break;
        }
    }
}

int Game::isNumber() {
    std::string input;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        try {
            const int option = std::stoi(input);
            return option;
        } catch (std::invalid_argument&) {
            Art::invalidOption();
            return 0;
        } catch (std::out_of_range&) {
            Art::invalidOption();
            return 0;
        }
    }
}

void Game::gameLoop(Player &player1, Player &player2, int &playerToPlay) {
    while (player1.getNumberShipsSunken() < player1.getFleetSize() || player2.getNumberShipsSunken() < player2.getFleetSize()) {
        using enum Color;
        int x; int y;
        std::cout << " ========= " << (playerToPlay == 1 ? getColorCode(RED) : getColorCode(RESET)) << player1.getName() << " (1)" << getColorCode(RESET) << " =========" << std::endl;
        player1.displayBoard();
        std::cout << " ========= " << (playerToPlay == 2 ? getColorCode(RED) : getColorCode(RESET)) << player2.getName() << " (2)" << getColorCode(RESET) << " =========" << std::endl;
        player2.displayBoard();
        UX::questionPosition(x, y);

        /* =========== Player 1 =========== */
        if (playerToPlay == 1) {
            if (player2.getAutoPlay()) {
                player2.autoHitCell();
                system("cls");
                playerToPlay = 2;
            } else {
                player2.hitCell(x - 1, y - 1);
                system("cls");
                playerToPlay = 2;
            }
        }

        /* =========== Player 2 =========== */
        if (playerToPlay == 2) {
            if (player1.getAutoPlay()) {
                player1.autoHitCell();
                system("cls");
                playerToPlay = 1;
            } else {
                player1.hitCell(x - 1, y - 1);
                system("cls");
                playerToPlay = 1;
            }
        }





    }
}