#include <iostream>
#include "board/boards.h"
#include "UI/Art.h"
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



int main() {
    system("cls");
    std::list Ships = {
        Ship(1, "Aircraft carrier", true, 5, false),
        Ship(2, "Battleship", false, 4, false),
        Ship(3, "Cruiser", true, 3, false),
        Ship(4, "Submarine", true, 3, false),
        Ship(5, "Destroyer", true, 2, false)
    };

    Art::showLandingPage();
    int option;
    cout << "> " << endl;
    cin >> option;

    switch (option) {
        case 1:
        {
            system("cls");
            Board board(10);
            board.play(Ships);
            main();
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
