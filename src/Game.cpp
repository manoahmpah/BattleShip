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
    int option;
    cout << "> ";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
        {
            chooseGameMode();

        }
        break;

        case 2:
            Art::showInstructions();
        cin.ignore();
        cin.get();
        break;
        case 3:
            cout << "Goodbye" << endl;

        default:
            cout << "Invalid option. Please try again." << endl;
        break;
    }
}
void Game::chooseGameMode() {
    std::cout << "Starting Battle Ship Game" << std::endl;
    int gameMode;
    Art::GameMode();
    std::cin >> gameMode;
    _player1 = Player("Maxime");
    _player2 = Player("Cédric");
    _player1.createBoard();
    _player2.createBoard();

    system("cls");
    switch (gameMode) {
        case 1: {
            _player1.placeAuto();
            _player1.hideBoard();
            _player2.setOpponentBoard(_player1.getBoard());

            _player2.PlaceShips();
            _player2.hideBoard();
            _player1.setOpponentBoard(_player2.getBoard());

            gameLoop(_player1, _player2, _playerToPlay);

            break;
        }
        case 2: {
            _player1.PlaceShips();
            _player1.hideBoard();
            _player2.setOpponentBoard(_player1.getBoard());

            _player2.PlaceShips();
            _player2.hideBoard();
            _player1.setOpponentBoard(_player2.getBoard());

            gameLoop(_player1, _player2, _playerToPlay);

            break;
        }
        default: {
            std::cout << "Invalid option. Please try again." << std::endl;

            chooseGameMode();

            break;
        }
    }
}

void Game::gameLoop(Player &player1, Player &player2, int &playerToPlay) {
    while (player1.getBoard().getNumberShipsSunken() < player1.getFleet().getSize()
                || player2.getBoard().getNumberShipsSunken() < player2.getFleet().getSize()) {

        using enum Color;
        int x; int y;
        std::cout << " ========= " << (playerToPlay == 1 ? getColorCode(RED) : getColorCode(RESET)) << player1.getName() << " (1)" << getColorCode(RESET) << " =========" << std::endl;
        player1.displayBoard();
        std::cout << " ========= " << (playerToPlay == 2 ? getColorCode(RED) : getColorCode(RESET)) << player2.getName() << " (2)" << getColorCode(RESET) << " =========" << std::endl;
        player1.displayOpponentBoard();
        UX::questionPosition(x, y);

        if (playerToPlay == 1) {
            player1.hitCell(x - 1, y - 1);
            system("cls");
            playerToPlay = 2;
        }
        else {
            player2.hitCell(x - 1, y - 1);
            system("cls");
            playerToPlay = 1;
        }
    }
}