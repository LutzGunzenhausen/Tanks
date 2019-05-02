#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include "Control/InputMask.hpp"
#include "GameState/GameState.h"

namespace Game {

class Game {
private:
    InputMask *inputMask = NULL;
    GameState *gameState = NULL;
    GameState *nextState = NULL;
    void mainLoop();
    void updateGameState();
    void readInput();
    void update();
    void paint();
    void paintOnScreen();
public:
    Game(GameState *initialState);
    ~Game();
};

}


#endif // GAME_H_INCLUDED
