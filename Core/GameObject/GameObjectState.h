#ifndef GAMEOBJECTSTATE_H_INCLUDED
#define GAMEOBJECTSTATE_H_INCLUDED

#include <iostream>
#include "../Media/GraphicsObject.h"
#include "../Util/Tupel.hpp"
#include "../Util/Rect.hpp"

namespace Game {

class GameObjectState {
private:
    GraphicsObject *graphicsObject = NULL;
    int imageCount;
    int delay;
    int imageIndex;
    int updateIndex;
public:
    GameObjectState(GraphicsObject *graphicsObject_);
    GameObjectState(GraphicsObject *graphicsObject_, int delay_);
    virtual ~GameObjectState() {
    }
    void update();
    void render(Tupel<double> *coord, double angle);
    void render(Tupel<double> *coord, double angle, Rect *visibleRect);
    int getWidth();
    int getHeight();
protected:
    virtual void animationFinished() {
    }
};

}

#endif // GAMEOBJECTSTATE_H_INCLUDED
