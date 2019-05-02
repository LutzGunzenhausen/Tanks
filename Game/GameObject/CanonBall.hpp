#ifndef CANONBALL_HPP_INCLUDED
#define CANONBALL_HPP_INCLUDED

namespace Game {

class CanonBall : public GameObject {
public:
    Tupel<double> *direction = NULL;
    bool firstExecution = true;

    CanonBall(Tupel<double> *coord_, Tupel<double> *dir, double angle)
    : GameObject(new GameObjectState(StaticServiceLocator::getMediaResourceStorage(
            )->getGraphicsObject(CANON_BALL)), coord_, angle), direction(dir) {
    }

    ~CanonBall() {
        delete direction;
        direction = NULL;
    }

    void update() {
        GameObject::update();
        if (!firstExecution) {
            // don't add the direction on the first cycle. So we avoid it spawning too far
            // away from the tank
            coord->add(direction);
        } else {
            firstExecution = false;
            StaticServiceLocator::getLoggingService()->log("Winkel: " + std::to_string(angle));        }
    }
};

}

#endif // CANONBALL_HPP_INCLUDED
