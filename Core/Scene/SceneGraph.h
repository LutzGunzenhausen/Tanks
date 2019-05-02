#ifndef SCENEGRAPH_H_INCLUDED
#define SCENEGRAPH_H_INCLUDED

#include "../Control/InputMask.hpp"
#include "../Util/List/List.hpp"
#include "../GameObjectV2/GameObject.h"

namespace Game {

class SceneGraph {
private:
    List<GameObjectV2> *gameObjects;

public:
    SceneGraph();
    ~SceneGraph();

    void update(InputMask *inputMask);
    void render();
};

}

#endif // SCENEGRAPH_H_INCLUDED
