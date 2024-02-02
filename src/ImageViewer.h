#ifndef _IMAGEVIEWER_H
#define _IMAGEVIEWER_H


#include <SDL2/SDL.h>
#include "Image.h"

/**
 * @class ImageViewer
 *
 * @brief Permet l'affichage de l'image à partir d'SDL2
 */
class ImageViewer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture *texture;

public:

    /**
     * @brief Initialise SDL2 et les attributs d'ImageViewer
     */
    ImageViewer();

    /**
     * @brief Ferme l'instance de SDL2
     */
    ~ImageViewer();

    /**
     * @brief Affiche l'image dans une fenêtre de SDL2
     *
     * @param im : Image
     */
    void afficher(const Image &im);
};


#endif
