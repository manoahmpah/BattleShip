#include <iostream>
#include <cctype>
#include <cstdlib>
#include <unistd.h>

#include "Board.h"
#include "Art.h"
#include "Fleet.h"
#include "Player.h"

#ifdef _WIN32
#include <Windows.h>
#define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); //Set console output to UTF-8.Visual C++ code on Windows.
#endif // _WIN32

#define RESET   "\033[0m"
#define RED     "\033[31m"

using namespace std;



int main() {
    system("cls");

    const Fleet fleet;
    list<Ship> Ships = fleet.Ships;

    Art::showLandingPage();
    int option;
    cout << "> ";
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
        {
            Player player1("Maxime");
            Player player2("Cédric");

            player1.autoPlaceShips();
            player2.autoPlaceShips();

            // main();
        }
        break;

        case 2:
            Art::showInstructions();
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
