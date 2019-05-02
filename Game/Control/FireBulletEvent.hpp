#ifndef FIREBULLETEVENT_HPP_INCLUDED
#define FIREBULLETEVENT_HPP_INCLUDED

#include "../../Core/Event/Event.h"
#include "../../Core/Util/Tupel.hpp"

namespace Game {

class FireBulletEvent : public Event {

public:
    Tupel<double> *startCoordinate = NULL;
    Tupel<double> *direction = NULL;
    double angle;

    FireBulletEvent(Tupel<double> *coord_, Tupel<double> *dir_, double angle_)
     : Event(PLAYER_FIRES_BULLET), startCoordinate(coord_), direction(dir_), angle(angle_) {
    }

    ~FireBulletEvent() {
        delete startCoordinate;
        startCoordinate = NULL;
        delete direction;
        direction = NULL;
    }
};

}

#endif // FIREBULLETEVENT_HPP_INCLUDED
