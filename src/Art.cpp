#include <iostream>
#include "Art.h"
#include <unistd.h>
#include "Color.h"

#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif

using namespace std;


void Art::showLandingPage() {
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

void Art::invalidOption() {
    system("cls");
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                           Invalid option. Please try again.                          ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "" << endl;
}

void Art::shipAlreadyPlaced() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                  Ship already posed.                                 ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << "" << endl;
}
void Art::gameOver() {
    #ifdef _WIN32
    SET_CONSOLE_UTF8
#endif
    using enum Color;
    system("cls");
    cout << "╔═════════════════════════════════════════════════════════════════════════════════════╗\n";
    sleep(1);
    cout << "║                                                                                     ║\n";
    cout << "║" << getColorCode(RED) <<  "                        ██████╗  █████╗ ███╗   ███╗███████╗                          " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                       ██╔════╝ ██╔══██╗████╗ ████║██╔════╝                          " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                       ██║  ███╗███████║██╔████╔██║█████╗                            " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                       ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝                            " << getColorCode(RESET) << "║\n";
    sleep(1);
    cout << "║" << getColorCode(RED) <<  "                       ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗                          " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                        ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝                          " << getColorCode(RESET) << "║\n";
    sleep(1);
    cout << "║                                                                                     ║\n";
    cout << "║" << getColorCode(RED) <<  "                       ██████╗ ██╗   ██╗███████╗██████╗                              " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                      ██╔═══██╗██║   ██║██╔════╝██╔══██╗                             " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                      ██║   ██║██║   ██║█████╗  ██████╔╝                             " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗                             " << getColorCode(RESET) << "║\n";
    cout << "║" << getColorCode(RED) <<  "                      ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║                             " << getColorCode(RESET) << "║\n";
    sleep(1);
    cout << "║" << getColorCode(RED) <<  "                       ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝                             " << getColorCode(RESET) << "║\n";
    cout << "║                                                                                     " << getColorCode(RESET) << "║\n";
    sleep(1);
    cout << "╚═════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << getColorCode(RESET);
}

void Art::showInstructions() {
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

void Art::gameMode() {
#ifdef _WIN32
    SET_CONSOLE_UTF8
#endif

    cout << "╔══════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                                                      ║\n";
    cout << "║     ██████╗  █████╗ ███╗   ███╗███████╗    ███╗   ███╗ ██████╗ ██████╗ ███████╗      ║\n";
    cout << "║    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ████╗ ████║██╔═══██╗██╔══██╗██╔════╝      ║\n";
    cout << "║    ██║  ███╗███████║██╔████╔██║█████╗      ██╔████╔██║██║   ██║██║  ██║█████╗        ║\n";
    cout << "║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║╚██╔╝██║██║   ██║██║  ██║██╔══╝        ║\n";
    cout << "║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗      ║\n";
    cout << "║     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝    ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝      ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                               \"Choose your Game mode !\"                              ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                             ╔═══════════════════════════╗                            ║\n";
    cout << "║                             ║   [1] solo mode           ║                            ║\n";
    cout << "║                             ║   [2] 2 Players mode      ║                            ║\n";
    cout << "║                             ║   [3] Exit                ║                            ║\n";
    cout << "║                             ╚═══════════════════════════╝                            ║\n";
    cout << "║                                                                                      ║\n";
    cout << "║                           Select an option and press Enter...                        ║\n";
    cout << "║                                                                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════╝\n";
}