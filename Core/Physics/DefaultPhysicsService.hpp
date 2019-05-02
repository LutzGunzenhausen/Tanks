#ifndef DEFAULTPHYSICSSERVICE_HPP_INCLUDED
#define DEFAULTPHYSICSSERVICE_HPP_INCLUDED

#include <math.h>
#include "../Util/AlignmentUtils.h"
#include "../Util/Tupel.hpp"
#include "../../Game/GameObject/Tank.hpp"

namespace Game {
class DefaultPhysicsService : public PhysicsService {

public:
    void update(GameObject *graphicsObject) {
        Tank *tank = dynamic_cast<Tank*>(graphicsObject);
        if (tank == NULL) {
            StaticServiceLocator::getLoggingService()->log("Found illegal object in PhysicsUpdater");
            return;
        }

        double angle = graphicsObject->angle;
        Tupel<double> *direction = AlignmentUtils::getDirectionForAngle(angle);
        Acceleration *acceleration = tank->acceleration;
        acceleration->update();
        direction->multiply(acceleration->getSpeed());
        AlignmentUtils::translateToFPS(direction);
        graphicsObject->coord->add(direction);
        delete direction;
    }
};

}
#endif // DEFAULTPHYSICSSERVICE_HPP_INCLUDED
