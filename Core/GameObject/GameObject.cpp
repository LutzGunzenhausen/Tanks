#ifndef GAMEOBJECT_CPP_INCLUDED
#define GAMEOBJECT_CPP_INCLUDED

#include "GameObject.hpp"

namespace Game {

    GameObject::GameObject(GameObjectState *objectState_, int x, int y)
     : GameObject(objectState_, new Tupel<double>((double) x, (double) y)) {

    }

    GameObject::GameObject(GameObjectState *objectState_, Tupel<double> *coord_)
     : GameObject(objectState_, coord_, 0.0) {
    }

    GameObject::GameObject(GameObjectState *objectState_, Tupel<double> *coord_, double angle_)
     : objectState(objectState_), coord(coord_), angle(angle_)
    {
    }

    GameObject::~GameObject() {
        delete objectState;
        objectState = NULL;
    }

    void GameObject::setState(GameObjectState *objectState_) {
        objectState = objectState_;
    }

    void GameObject::render() {
        objectState->render(coord, angle);
    }

    int GameObject::getWidth() {
        return objectState->getWidth();
    }

    int GameObject::getHeight() {
        return objectState->getHeight();
    }

    void GameObject::update() {
        objectState->update();
    }

    void GameObject::changeAngle(double delta) {
        angle += delta;
    }
}

#endif // GAMEOBJECT_CPP_INCLUDED
