#ifndef _IMAGEVIEWER_H
#define _IMAGEVIEWER_H


#include <SDL2/SDL.h>
class Image;

class ImageViewer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture *texture;

public:
    ImageViewer();

    ~ImageViewer();

    void afficher(Image im);
};


#endif
