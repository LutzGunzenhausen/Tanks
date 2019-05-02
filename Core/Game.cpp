#include <chrono>
#include "Game.h"
#include "StaticServiceLocator.h"

namespace Game {

    Game::Game(GameState *initialState) : gameState(initialState) {
        inputMask = new InputMask();
        mainLoop();
    }

    void Game::mainLoop() {
        clock_t startTime;
        long elapsed;
        long waitTime;
        while (StaticServiceLocator::getGraphicsService()->isGameRunning()) {
            startTime = clock();
            updateGameState();
            readInput();
            update();
            paint();
            paintOnScreen();
            elapsed = clock() - startTime;
            waitTime = DELAY_TIME - elapsed;
            if (waitTime < 0) {
                waitTime = 10;
            }
            StaticServiceLocator::getGraphicsService()->delay(waitTime);
        }
    }

    void Game::updateGameState() {
        if (nextState == NULL) {
            return;
        }

        delete gameState;
        gameState = nextState;

    }

    void Game::readInput() {
        StaticServiceLocator::getGraphicsService()->updateInputMask(inputMask);
    }

    void Game::update() {
        nextState = gameState->update(inputMask);
    }

    void Game::paint() {
        gameState->paint();
    }

    void Game::paintOnScreen() {
        StaticServiceLocator::getGraphicsService()->flipBuffer();
    }
}
