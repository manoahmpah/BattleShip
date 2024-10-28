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
    system("cls");
    switch (gameMode) {
        case 1: {
            _player1 = Player("Maxime");
            _player2 = Player("Cédric");

            _player1.getBoard().createBoard();
            _player1.getBoard().placeAutomatically(_player1.getFleet());
            _player1.getBoard().hideBoard();
            _player2.setOpponentBoard(_player1.getBoard());

            _player2.getBoard().createBoard();
            _player2.PlaceShips();
            _player1.setOpponentBoard(_player2.getBoard());

            _player2.getBoard().hideBoard();

            gameLoop(_player1, _player2, _playerToPlay);


            break;
        }
        case 2: {
            _player1 = Player("Maxime");
            _player2 = Player("Cédric");

            _player1.getBoard().createBoard();
            _player1.getBoard().placeAutomatically(_player1.getFleet());
            _player1.getBoard().hideBoard();
            _player2.setOpponentBoard(_player1.getBoard());

            _player2.getBoard().createBoard();
            _player2.PlaceShips();
            _player2.getBoard().hideBoard();
            _player1.setOpponentBoard(_player2.getBoard());

            gameLoop(_player1, _player2, _playerToPlay);

            break;
        }
        default: {
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }
}

void Game::gameLoop(Player &player1, Player &player2, int &playerToPlay) {
    while (player1.getBoard().getNumberShipsSunken() < player1.getFleet().getSize()
                || player2.getBoard().getNumberShipsSunken() < player2.getFleet().getSize()) {
        int x; int y;
        if (playerToPlay == 1) {
            player1.displayBoard();
            UX::questionPosition(x, y);
            player1.hitCell(x - 1, y - 1);
            system("cls");
            std::cout << " ========= " << player1.getName() << " =========" << std::endl;
            player1.displayBoard();
            playerToPlay = 2;
        }
        else {
            player2.displayBoard();
            UX::questionPosition(x, y);
            player2.hitCell(x - 1, y - 1);
            system("cls");
            std::cout << " ========= " << player2.getName() << " =========" << std::endl;
            player2.displayBoard();
            playerToPlay = 1;
        }
    }
}