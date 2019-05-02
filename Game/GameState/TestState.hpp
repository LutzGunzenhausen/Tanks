#ifndef TESTSTATE_HPP_INCLUDED
#define TESTSTATE_HPP_INCLUDED

#include "TestState.h"
#include "../Control/PlayerUpdater.h"
#include "../../Core/Event/EventListener.h"
#include "../../Core/Event/EventBus.h"

namespace Game {

    TestState::TestState() {
        sceneGraph = new SceneGraph();
        GraphicsObject *playerGraph = StaticServiceLocator::getMediaResourceStorage()->getGraphicsObject(SQUARE);
        player = new Tank(new GameObjectState(playerGraph), 10, 10);
        updater = new PlayerUpdater(player);

        TestStateListener *newlistener = new TestStateListener();
        newlistener->state = this;
        listener = newlistener;
        StaticServiceLocator::getEventBus()->addEventListener(listener);
    }

    TestState::~TestState() {
        delete ball;
        ball = NULL;
        delete updater;
        updater = NULL;
        delete player;
        player = NULL;
    }

    GameState* TestState::update(InputMask *inputMask) {
        player->update();
        updater->update(inputMask);
        if (ball != NULL) {
            ball->update();
        }
        return NULL;
    }

    void TestState::paint() {
        player->render();
        if (ball != NULL) {
            ball->render();
        }
    }

    void TestState::listen(Event *event) {
        StaticServiceLocator::getLoggingService()->log("Event!!!");
        if (event->EVENT_TYPE == PLAYER_FIRES_BULLET) {
            FireBulletEvent *fbEvent = (FireBulletEvent*) event;
            if (ball != NULL) {
                delete ball;
                StaticServiceLocator::getLoggingService()->log("Löschen!");
                ball = NULL;
                StaticServiceLocator::getLoggingService()->log("Gelöscht!");
            }
            ball = new CanonBall(fbEvent->startCoordinate, fbEvent->direction, fbEvent->angle);
            StaticServiceLocator::getLoggingService()->log("Neuen angelegt");
        }
    }

    void TestStateListener::eventOcurred(Event *event) {
        state->listen(event);
    }
}

#endif // TESTSTATE_HPP_INCLUDED
