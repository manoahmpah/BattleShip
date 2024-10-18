//
// Created by MPAH on 18/10/2024.
//

#include "UX.h"

#include <iostream>
#include <ostream>
#include <list>
#include "Ship.h"
#ifdef _WIN32
#include <Windows.h>
#define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); //Set console output to UTF-8.Visual C++ code on Windows.
#endif // _WIN32
using namespace std;

void UX::questionPosition(int &x, int &y) {
        char letter;
        cout << "Enter a letter between A and J :" << endl;
        cin >> letter;
        x = toupper(letter) - 64;
        cout << "Enter a number between 1 and 10 :" << endl;
        cin >> y;
}

void UX::questionAddShip(int &chosenShip, const std::list<Ship> &Ships) {
#ifdef _WIN32
        SET_CONSOLE_UTF8
    #endif

        cout << "╔══════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                                                          ║\n";
        cout << "║                    Which ship do you want to add?                        ║\n";
        cout << "║                                                                          ║\n";

        size_t maxLength = 0;
        for (const auto &ship : Ships) {
                if (!ship.isPosed) {
                        maxLength = std::max(maxLength, ship.name.length());
                }
        }

        int i = 1;
        for (const auto &ship : Ships) {
                if (!ship.isPosed) {
                        size_t padding = maxLength - ship.name.length();
                        cout << "                      " << i << " - " << ship.name << string(padding, ' ')
                               << " [ " << ship.size << " of weight ]                      \n";
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

