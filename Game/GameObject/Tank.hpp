#ifndef TANK_HPP_INCLUDED
#define TANK_HPP_INCLUDED

#include "../../Core/GameObject/GameObject.hpp"
#include "../Control/Acceleration.hpp"
#include "../../Core/Media/GraphicsObject.h"
#include "../Resource/ResourceIdentifiers.h"
#include "../../Core/Util/AlignmentUtils.h"
#include "ProgressBar.hpp"

namespace Game {

class Tank : public GameObject {

public:
    Acceleration *acceleration = NULL;
    double canonAngle;
    GraphicsObject *canon = NULL;
    ProgressBar *progressBar = NULL;

    Tank(GameObjectState *objectState_, int x, int y)
     : GameObject(objectState_, x, y), canonAngle(0.0) {
        acceleration = new Acceleration(20.0, 300.0);
        canon = StaticServiceLocator::getMediaResourceStorage()->getGraphicsObject(CANON);
        progressBar = new ProgressBar(this->coord, 100, 0);
    }

    void render() {
        GameObject::render();
        canon->renderObject((int) coord->getFirst() + 3, (int) coord->getSecond() + 3 , 0, angle + canonAngle);
        progressBar->render();
    }

    void changeCanonAngle(double angleDelta) {
        canonAngle += angleDelta;
    }

    Tupel<double> *getCanonBallStart() {
        int middlePointX = coord->getFirst() + 8;
        int middlePointY = coord->getSecond() + 8;
        int canonLength = canon->width;

        Tupel<double> *direction = getCanonBallDirection();
        direction->multiply((double) canonLength);
        Tupel<double> *addition = new Tupel<double>((double) middlePointX, (double) middlePointY);
        direction->add(addition);
        delete addition;
        return direction;
    }

    void update() {
        GameObject::update();
        progressBar->update();
    }

    Tupel<double> *getCanonBallDirection() {
        double angleSum = angle + canonAngle;
        Tupel<double> *direction = AlignmentUtils::getDirectionForAngle(angleSum);
        return direction;
    }
};

}


#endif // TANK_HPP_INCLUDED
