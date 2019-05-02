#ifndef SPACEINVADERSRESOURCESTORAGE_H_INCLUDED
#define SPACEINVADERSRESOURCESTORAGE_H_INCLUDED

#include "ResourceIdentifiers.h"

namespace Game {

class SpaceInvadersResourceStorage : public MediaResourceStorage {
public:
    SpaceInvadersResourceStorage() {
        graphicsObjects = new GraphicsObject*[ELEMENT_COUNT];
        graphicsObjects[SQUARE] = StaticServiceLocator::getGraphicsService(
            )->createObjectFromFile("img/Square.png", new Tupel<int>(8, 8));
        graphicsObjects[CANON] = StaticServiceLocator::getGraphicsService(
            )->createObjectFromFile("img/Canon.png", new Tupel<int>(6, 6));
        graphicsObjects[CANON_BALL] = StaticServiceLocator::getGraphicsService(
            )->createObjectFromFile("img/CanonBall.png");
        graphicsObjects[REFRESH_BAR] = StaticServiceLocator::getGraphicsService(
            )->createObjectFromFile("img/RefreshBar.png");
//        audioObjects[SUCCESS_SOUND] = StaticServiceLocator::getGraphicsService(
//            )->getAudioObject("sounds/Success.wav");
    }
};
}

#endif // SPACEINVADERSRESOURCESTORAGE_H_INCLUDED
