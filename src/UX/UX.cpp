//
// Created by MPAH on 18/10/2024.
//

#include "UX.h"

#include <iostream>
#include <ostream>
#include <list>
#include "../Ship/Ship.h"

using namespace std;

void UX::questionPosition(int &x, int &y) {
        char letter;
        cout << "Enter a letter between A and J :" << endl;
        cin >> letter;
        x = toupper(letter) - 64;
        cout << "Enter a number between 1 and 10 :" << endl;
        cin >> y;
}

void UX::questionAddShip(int &chosenShip, const list<Ship> &Ships) {
        cout << "Which ship do you want to add?" << endl;
        for (int i = 0; i < Ships.size(); i++) {
                auto ship = Ships.begin();
                std::advance(ship, i);

                if (ship->isPosed) {
                        continue;
                }

                cout << i + 1 << " - " << ship->name << endl;
        }

        cin >> chosenShip;
}
