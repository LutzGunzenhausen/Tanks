#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "../Util/Bounds.hpp"

namespace Game {

class GameObjectV2 {
private:
    Bounds *bounds;
    int layoutIdentifier;
    // upper Border = 1000?
    int renderingCount;
public:

    virtual void update();

};

}

#endif // GAMEOBJECT_H_INCLUDED
