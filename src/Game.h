#ifndef GAME_H
#define GAME_H

#include "Player.h"


class Game {
public:
    Game(const Player &player1, const Player &player2);
    void startGame();

private:
    void chooseGameMode();
    static void gameLoop(Player &player1, Player &player2, int &playerToPlay);
    Player _player1;
    Player _player2;
    int _playerToPlay = 1;
};



#endif //GAME_H
