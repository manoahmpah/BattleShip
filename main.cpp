#include <iostream>
#include "classes/board/boards.h"
#include <list>
#include <cctype>
#include <cstdlib>
#include <unistd.h>

#ifdef _WIN32
#include <Windows.h>
#define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); //Set console output to UTF-8.Visual C++ code on Windows.
#endif // _WIN32

#define RESET   "\033[0m"
#define RED     "\033[31m"

using namespace std;

void questionAddShip(int &chosenShip, const list<Ship> &Ships);
void questionPosition(int &x, int &y);
void placeManually(const Board &board, list<Ship> &Ships);
void showLandingPage();
void showInstructions();
void gameOver();



int main() {
    system("cls");
    std::list Ships = {
        Ship(1, "Aircraft carrier", true, 5, false),
        Ship(2, "Battleship", false, 4, false),
        Ship(3, "Cruiser", true, 3, false),
        Ship(4, "Submarine", true, 3, false),
        Ship(5, "Destroyer", true, 2, false)
    };

    showLandingPage();
    int option;
    cout << "> " << endl;
    cin >> option;
    switch (option) {
        case 1:
        {
            system("cls");
            Board board(10);
            cout << "Starting Battle Ship Game" << endl;
            placeManually(board, Ships);
            cout << " =========== All ships placed ===========" << endl;
            cout << board << endl;
            cout << endl;

            board.hiddenBoard();
            cout << "========= hidden board =========" << endl;
            cout << board << endl;


            while (board.numberShipsSunken < Ships.size()) {
                int x; int y;
                questionPosition(x, y);
                board.hitCell(x - 1, y - 1);
                system("cls");
                cout << board << endl;
            }
            gameOver();
            sleep(3);
            main();
        }
        break;

        case 2:
            showInstructions();
            cin.ignore();
            cin.get();
            main();
        break;
        case 3:
            cout << "Goodbye" << endl;
        return 0;

        default:
            cout << "Invalid option. Please try again." << endl;
        break;
    }




    return 0;
}

void placeManually(const Board &board, list<Ship> &Ships) {
    int x; int y;
    int chosenShip;

    cout << board << endl;

    while (!Ships.empty()) {
        questionAddShip(chosenShip, Ships);

        // ======== Check if player choose a right ship ======== //
        if (chosenShip < 1 || chosenShip > Ships.size()) {
            cout << "Invalid ship" << endl;
            continue;
        }
        questionPosition(x, y);

        auto ship = Ships.begin();
        std::advance(ship, chosenShip - 1);
        ship->isPosed = true;

        if (!board.addShip(x - 1, y - 1, *ship)) {
            cout << board << endl;
            continue;
        }

        system("cls");
        cout << board << endl;
    }
}

void questionAddShip(int &chosenShip, const list<Ship> &Ships) {
    cout << "Which ship do you want to add?" << endl;
    for (int i = 0; i < Ships.size(); i++) {
        auto ship = Ships.begin();
        std::advance(ship, i);
        cout << i + 1 << " - " << ship->name << endl;
    }

    cin >> chosenShip;
}

void questionPosition(int &x, int &y) {
    char letter;
    cout << "Enter a letter between A and J :" << endl;
    cin >> letter;
    x = toupper(letter) - 64;
    cout << "Enter a number between 1 and 10 :" << endl;
    cin >> y;
}


void showLandingPage() {
#ifdef _WIN32
    SET_CONSOLE_UTF8
#endif
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                                      ║\n";
    cout << "║     ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗     ║\n";
    cout << "║     ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗    ║\n";
    cout << "║     ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝    ║\n";
    cout << "║     ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝     ║\n";
    cout << "║     ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║         ║\n";
    cout << "║     ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝         ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                            WELCOME TO THE BATTLESHIP GAME                            ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                          \"Prepare for epic naval battles!\"                           ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                             ╔═══════════════════════════╗                            ║\n";
    cout << "║                             ║   [1] Start Game          ║                            ║\n";
    cout << "║                             ║   [2] Instructions        ║                            ║\n";
    cout << "║                             ║   [3] Exit                ║                            ║\n";
    cout << "║                             ╚═══════════════════════════╝                            ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                           Select an option and press Enter...                        ║\n";
    cout << "║                                                                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝\n";

}


void showInstructions() {
    system("cls");
    cout << "███████████████████████████████████████████████████████████████████\n";
    cout << "█                     BATTLESHIP INSTRUCTIONS                     █\n";
    cout << "███████████████████████████████████████████████████████████████████\n";
    cout << "█ 1. The game consists of two players, each with their own fleet. █\n";
    cout << "█ 2. Each fleet contains various ships:                           █\n";
    cout << "█    - Aircraft Carrier: 5 spaces                                 █\n";
    cout << "█    - Battleship: 4 spaces                                       █\n";
    cout << "█    - Cruiser: 3 spaces                                          █\n";
    cout << "█    - Submarine: 3 spaces                                        █\n";
    cout << "█    - Destroyer: 2 spaces                                        █\n";
    cout << "█ 3. Players take turns to guess the coordinates of the enemy's   █\n";
    cout << "█    ships on a 10x10 grid.                                       █\n";
    cout << "█ 4. If a player hits a ship, they get another turn.              █\n";
    cout << "█ 5. The first player to sink all enemy ships wins the game!      █\n";
    cout << "█                                                                 █\n";
    cout << "█                  GOOD LUCK AND HAVE FUN!                        █\n";
    cout << "███████████████████████████████████████████████████████████████████\n";
    cout << "█ Press Enter to return to the main menu...                       █\n";
    cout << "███████████████████████████████████████████████████████████████████\n";
}

void gameOver() {
#ifdef _WIN32
    SET_CONSOLE_UTF8
#endif
    system("cls");
    cout << "╔═════════════════════════════════════════════════════════════════════════════════════╗\n";
    sleep(1);
    cout << "║                                                                                     ║\n";
    cout << "║" << RED <<  "                        ██████╗  █████╗ ███╗   ███╗███████╗                          " << RESET << "║\n";
    cout << "║" << RED <<  "                       ██╔════╝ ██╔══██╗████╗ ████║██╔════╝                          " << RESET << "║\n";
    cout << "║" << RED <<  "                       ██║  ███╗███████║██╔████╔██║█████╗                            " << RESET << "║\n";
    cout << "║" << RED <<  "                       ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝                            " << RESET << "║\n";
    sleep(1);
    cout << "║" << RED <<  "                       ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗                          " << RESET << "║\n";
    cout << "║" << RED <<  "                        ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝                          " << RESET << "║\n";
    sleep(1);
    cout << "║                                                                                     ║\n";
    cout << "║" << RED <<  "                       ██████╗ ██╗   ██╗███████╗██████╗                              " << RESET << "║\n";
    cout << "║" << RED <<  "                      ██╔═══██╗██║   ██║██╔════╝██╔══██╗                             " << RESET << "║\n";
    cout << "║" << RED <<  "                      ██║   ██║██║   ██║█████╗  ██████╔╝                             " << RESET << "║\n";
    cout << "║" << RED <<  "                      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗                             " << RESET << "║\n";
    cout << "║" << RED <<  "                      ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║                             " << RESET << "║\n";
    sleep(1);
    cout << "║" << RED <<  "                       ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝                             " << RESET << "║\n";
    cout << "║                                                                                     " << RESET << "║\n";
    sleep(1);
    cout << "╚═════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
}