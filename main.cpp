#include "Game/StaticInitializer.hpp"
#include "Core/Game.h"
#include "Game/GameState/TestState.hpp"

#include "Core/Util/AlignmentUtils.h"
#include "Core/Util/Tupel.hpp"

//void informMe(Game::Event *event);

int main(int argc, char** argv) {
    Game::Tupel<double> *tupel = Game::AlignmentUtils::getDirectionForAngle(90);
    std::cout << "X: " << tupel->getFirst() << " Y: " << tupel->getSecond() << std::endl;

    Game::StaticInitializer::initialize();

    new Game::Game(new Game::TestState());
    return 0;
}
