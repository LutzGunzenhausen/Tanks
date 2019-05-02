#ifndef TESTSTATE_H_INCLUDED
#define TESTSTATE_H_INCLUDED

#include "../Control/PlayerUpdater.h"
#include "../../Core/Event/EventListener.h"
#include "../GameObject/CanonBall.hpp"
#include "../../Core/Scene/SceneGraph.h"

namespace Game {
class TestState : public GameState {

private:
Tank *player = NULL;
PlayerUpdater *updater = NULL;
EventListener *listener = NULL;
CanonBall *ball = NULL;
SceneGraph *sceneGraph = NULL;

public:
    TestState();
    ~TestState();
    void listen(Event *event);
    GameState* update(InputMask *inputMask);
    void paint();
};

class TestStateListener : public EventListener {
public:
    TestState *state = NULL;
    void eventOcurred(Event *event);
};
}



#endif // TESTSTATE_H_INCLUDED
