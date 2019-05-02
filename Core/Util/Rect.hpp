#ifndef RECT_HPP_INCLUDED
#define RECT_HPP_INCLUDED

#include "Tupel.hpp"

namespace Game {

class Rect {
public:
    Tupel<int> *coord = NULL;
    int width = 0;
    int height = 0;

    Rect(Tupel<int> *coord_, int width_, int height_)
     : coord(coord_), width(width_), height(height_) {
     }
};

}


#endif // RECT_HPP_INCLUDED
