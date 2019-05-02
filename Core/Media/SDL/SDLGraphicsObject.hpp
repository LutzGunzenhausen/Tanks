#ifndef SDLGRAPHICSOBJECT_HPP_INCLUDED
#define SDLGRAPHICSOBJECT_HPP_INCLUDED

#include <SDL.h>
#include "../../CoreConstants.h"
#include "../../Util/Rect.hpp"

namespace Game {

class SDLGraphicsObject : public GraphicsObject {
private:
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect *sourceRect = NULL;
    SDL_Rect *displayRect = NULL;
    SDL_Point *center = NULL;

public:
    SDLGraphicsObject(SDL_Texture *texture_, SDL_Renderer *renderer_)
     : SDLGraphicsObject(texture_, renderer_, NULL) {
    }
    SDLGraphicsObject(SDL_Texture *texture_, SDL_Renderer *renderer_, SDL_Point *center_)
     : GraphicsObject(0, 0), renderer(renderer_), texture(texture_), center(center_) {
         SDL_QueryTexture(texture, NULL, NULL, &imageWidth, &height);
         width = imageWidth;
         displayRect = new SDL_Rect();
         displayRect->w = width;
         displayRect->h = height;
         sourceRect = new SDL_Rect();
         sourceRect->w = width;
         sourceRect->h = height;
         sourceRect->x = 0;
         sourceRect->y = 0;
    }

    ~SDLGraphicsObject() {
        SDL_DestroyTexture(texture);
        texture = NULL;
        delete sourceRect;
        delete displayRect;
        sourceRect = NULL;
        displayRect = NULL;
    }

    void updateTileWidth(int width_) {
        sourceRect->w = width_;
        displayRect->w = width_;
        width = width_;
    }

    void renderObject(int xCoord, int yCoord, int index, double angle) {
        renderObject(xCoord, yCoord, index, angle, NULL);
    }

    void renderObject(int xCoord, int yCoord, int index, double angle, Rect *visibleRect) {
        displayRect->x = xCoord;
        displayRect->y = WINDOW_HEIGHT - yCoord - height;
        sourceRect->x = index * width;
        sourceRect->y = 0;
        if (visibleRect != NULL) {
            sourceRect->x += visibleRect->coord->getFirst();
            sourceRect->y += visibleRect->coord->getSecond();
            displayRect->w = visibleRect->width;
            sourceRect->w = visibleRect->width;
            sourceRect->h = visibleRect->height;
        } else {
            displayRect->w = width;
            sourceRect->w = displayRect->w;
            sourceRect->h = displayRect->h;
        }
        SDL_RenderCopyEx(renderer, texture, sourceRect, displayRect, angle, center, SDL_FLIP_NONE);
    }
};

}

#endif // SDLGRAPHICSOBJECT_HPP_INCLUDED
