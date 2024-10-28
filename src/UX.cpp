#include "UX.h"

#include <iostream>
#include <ostream>
#include <vector>

#include "Ship.h"
#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif
using namespace std;

void UX::questionPosition(int &x, int &y) {
        char letter;
        cout << "Enter a letter between A and J :" << endl;
        cin >> letter;
        x = toupper(letter) - 64;
        cout << "Enter a number between 1 and 10 :" << endl;
        cin >> y;
}

void UX::questionAddShip(int &chosenShip, const vector<Ship> &Ships) {
#ifdef _WIN32
        SET_CONSOLE_UTF8
    #endif

        cout << "╔══════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                                                          ║\n";
        cout << "║                    Which ship do you want to add?                        ║\n";
        cout << "║                                                                          ║\n";

        size_t maxLength = 0;
        for (const auto &ship : Ships) {
                if (!ship.getIsPosed()) {
                        maxLength = std::max(maxLength, ship.getName().length());
                }
        }

        int i = 1;
        for (const auto &ship : Ships) {
                if (!ship.getIsPosed()) {
                        size_t padding = maxLength - ship.getName().length();
                        cout << "                      " << ship.getId() << " - " << ship.getName() << string(padding, ' ')
                               << " [ " << ship.getSize() << " of weight ]                      \n";
                        i++;
                }
        }

        cout << "║                                                                          ║\n";
        cout << "║                   Select a ship by entering a number:                    ║\n";
        cout << "║                                                                          ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════╝\n";
        cout << "> ";
        cin >> chosenShip;
}

