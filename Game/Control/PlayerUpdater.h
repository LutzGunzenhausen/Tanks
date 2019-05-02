#ifndef PLAYERUPDATER_H_INCLUDED
#define PLAYERUPDATER_H_INCLUDED

#include "../../Core/Control/Updater.h"
#include "../GameObject/Tank.hpp"
#include "../../Core/Event/Event.h"
#include "../../Core/Event/EventBus.h"
#include "FireBulletEvent.hpp"

namespace Game {

class PlayerUpdater : public Updater {
private:
    Tank *playerObject = NULL;
    bool spaceWasReleased;
public:
    PlayerUpdater(Tank *playerObject_)
        : playerObject(playerObject_), spaceWasReleased(true) {
    }
    void update(InputMask *inputMask) {
        Direction direction = STANDING;
        int factor = 1;
        if (inputMask->isUpActive()) {
            direction = FORWARD;
        } else if (inputMask->isDownActive()) {
            direction = BACKWARDS;
            factor = -1;
        }

        if (inputMask->isAActive()) {
            StaticServiceLocator::getLoggingService()->log("A aktiv");
            playerObject->changeCanonAngle(-7);
        } else if (inputMask->isDActive()) {
            StaticServiceLocator::getLoggingService()->log("D aktiv");
            playerObject->changeCanonAngle(7);
        }

        if (inputMask->isSpaceActive()) {
            if (spaceWasReleased) {
                spaceWasReleased = false;
                // fire Event
                Tupel<double> *startCoordinate = playerObject->getCanonBallStart();
                Tupel<double> *direction = playerObject->getCanonBallDirection();
                double angle = AlignmentUtils::getAngleByTupel(direction);
                direction->multiply(10);
                Event *event = new FireBulletEvent(startCoordinate, direction, angle);
                StaticServiceLocator::getEventBus()->publishEvent(event);
                delete event;
            }
        } else {
            spaceWasReleased = true;
        }

        if (inputMask->isLeftActive()) {
            playerObject->changeAngle(-5 * factor);
        }
        if (inputMask->isRightActive()) {
            playerObject->changeAngle(5 * factor);
        }

        playerObject->acceleration->setDirection(direction);
        StaticServiceLocator::getPhysicsService()->update(playerObject);
    }
};
}
#endif // PLAYERUPDATER_H_INCLUDED
