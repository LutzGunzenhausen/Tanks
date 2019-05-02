#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

#include "GameObjectState.h"
#include "../Util/Tupel.hpp"

namespace Game {

class GameObject {
protected:
    GameObjectState *objectState = NULL;
public:
    Tupel<double> *coord = NULL;
    double angle = 0.0;

    GameObject(GameObjectState *objectState_, int x, int y);
    GameObject(GameObjectState *objectState_, Tupel<double> *coord_);
    GameObject(GameObjectState *objectState_, Tupel<double> *coord_, double angle);
    virtual ~GameObject();
    void setState(GameObjectState *objectState_);
    virtual void render();
    int getWidth();
    int getHeight();
    virtual void update();
    void changeAngle(double delta);
};

}

#endif // GAMEOBJECT_HPP_INCLUDED
