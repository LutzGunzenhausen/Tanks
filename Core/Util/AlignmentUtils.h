#ifndef ALIGNMENTUTILS_H_INCLUDED
#define ALIGNMENTUTILS_H_INCLUDED

#include <math.h>

#include "Tupel.hpp"
#include "../CoreConstants.h"

namespace Game {

class AlignmentUtils {

private:
    static constexpr double PI = 3.1415926535897932384626433832795;
    static constexpr double RADIANS = PI / 180;
    static constexpr double TRANSLATION_FACTOR = 1.0 / FRAMES_PER_SECOND;

public:
    static inline int centerAroundCoordinate(GraphicsObject *object, int x) {
        return x - (object->width / 2);
    }
    static inline int centerAroundCoordinate(GameObjectState *object, int x) {
        return x - (object->getWidth() / 2);
    }

    static inline int getPassedDuration(int updateFrames) {
        return DELAY_TIME * updateFrames;
    }

    static inline int getDistancePerFrame(int distancePerSecond) {
        return distancePerSecond * TRANSLATION_FACTOR;
    }

    static inline int getMin(int a, int b) {
        return (a < b) ? a : b;
    }

    static inline int getMax(int a, int b) {
        return (a > b) ? a : b;
    }

    static inline int getAbsHorizontalDistance(Tupel<int> *a, Tupel<int> *b) {
        return getAbs(a->getFirst() - b->getSecond());
    }

    static inline int getAbs(int a) {
        return a > 0 ? a : -a;
    }

    static inline Tupel<double> *getDirectionForAngle(double angle) {
        double x = cos(angle * RADIANS);
        // Minus, because for SDL the angle goes right - not left
        double y = -sin(angle * RADIANS);
        Tupel<double> *direction = new Tupel<double>(x, y);
        return direction;
    }

    static inline double getAngleByTupel(Tupel<double> *tupel) {
        return -asin(tupel->getSecond()) / RADIANS;
    }

    static inline void translateToFPS(Tupel<double> *deltaTupel) {
        deltaTupel->multiply(TRANSLATION_FACTOR);
    }
};

}

#endif // ALIGNMENTUTILS_H_INCLUDED
