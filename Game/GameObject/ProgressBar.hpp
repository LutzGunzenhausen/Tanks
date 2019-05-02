#ifndef PROGRESSBAR_HPP_INCLUDED
#define PROGRESSBAR_HPP_INCLUDED

#include "../../Core/Util/Rect.hpp"

namespace Game {

class ProgressBar : public GameObject {
private:

    int maximum;
    int currentValue;
    int ticker;
    Rect *visibleRect = NULL;
public:
    ProgressBar(Tupel<double> *tankCoord_, int maximum_, int currentValue_)
     : GameObject(new GameObjectState(StaticServiceLocator::getMediaResourceStorage(
            )->getGraphicsObject(REFRESH_BAR)), tankCoord_),
            maximum(maximum_), currentValue(currentValue_), ticker(0) {
        visibleRect = new Rect(new Tupel<int>(0, 0), getWidth(), getHeight());
    }

    void update() {
        ticker++;
        if ((ticker % 2) == 0) {
            currentValue++;
            if (currentValue > maximum) {
                currentValue = 0;
            }
        }
    }

    void render() {
        StaticServiceLocator::getLoggingService()->log("Current: " + std::to_string(currentValue));
        StaticServiceLocator::getLoggingService()->log("Maximum: " + std::to_string(maximum));
        double ratio = currentValue / (double) maximum;
        StaticServiceLocator::getLoggingService()->log("Bin bei jenem: " + std::to_string(ratio));
        visibleRect->width = (int) (getWidth() * ratio);
        StaticServiceLocator::getLoggingService()->log("Bin da");
        objectState->render(coord, angle, visibleRect);
    }

};

}

#endif // PROGRESSBAR_HPP_INCLUDED
