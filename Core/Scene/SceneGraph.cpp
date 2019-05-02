#include "SceneGraph.h"
#include "../Control/InputMask.hpp"
#include "../Util/List/List.hpp"
#include "../GameObjectV2/GameObject.h"

namespace Game {

    SceneGraph::SceneGraph() {
        gameObjects = new List<GameObjectV2>();
    }

    SceneGraph::~SceneGraph() {
    }

    void SceneGraph::update(InputMask *inputMask) {
        for (int i = 0; i < gameObjects->getElementCount(); i++) {
            gameObjects->getElementAt(i)->update();
        }
    }

    void SceneGraph::render() {
    }


}
