#include <iostream>
#include <unistd.h>
#include "Player.h"
#include "Game.h"

#ifdef _WIN32
    #include <windows.h>
    #define SET_CONSOLE_UTF8 SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
#else
    #define SET_CONSOLE_UTF8
#endif

using namespace std;

int main() {
    system("cls");
    Game game(Player("Maxime"), Player("Cédric"));
    game.startGame();

    return 0;
}
