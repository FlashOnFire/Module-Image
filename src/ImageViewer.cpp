#include "ImageViewer.h"

#include <iostream>

ImageViewer::ImageViewer() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    surface = nullptr;
    texture = nullptr;
}

ImageViewer::~ImageViewer() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void ImageViewer::afficher(const Image& im) {
    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
    SDL_RenderClear(renderer);

    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }

    surface = SDL_CreateRGBSurfaceFrom(im.tab, im.dimx, im.dimy, 24, im.dimx * 3, 0, 0, 0, 0);

    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    bool running = true;
    SDL_Event e;
    while (running) {
        if (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
}
