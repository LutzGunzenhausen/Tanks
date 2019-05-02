#ifndef BOUNDS_HPP_INCLUDED
#define BOUNDS_HPP_INCLUDED

#include "Tupel.hpp"

namespace Game {

class Bounds {
private:
    Tupel<int> *coord;
    double angle;
    int width;
    int height;
public:
    Bounds() : coord(new Tupel<int>()), angle(0.0), width(0), height(0) {
    }
};

}

#endif // BOUNDS_HPP_INCLUDED
