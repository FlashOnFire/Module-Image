#include "ImageViewer.h"

#include <iostream>

ImageViewer::ImageViewer() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200,
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
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }

    surface = SDL_CreateRGBSurfaceFrom(im.tab, im.dimx, im.dimy, 24, im.dimx * 3, 0x0000ff, 0x00ff00, 0xff0000, 0);

    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    bool running = true;
    float zoom = 1.0f;
    SDL_Rect dstRect;

    SDL_Event e;
    while (running) {
        SDL_RenderClear(renderer);
        if (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                        case SDLK_t:
                            zoom += 0.25f;
                            break;
                        case SDLK_g:
                            zoom -= 0.25f;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }


        dstRect.w = im.dimx * zoom;
        dstRect.h = im.dimy * zoom;
        dstRect.x = 100.0 - dstRect.w / 2.0;
        dstRect.y = 100.0 - dstRect.h / 2.0;

        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
        SDL_RenderPresent(renderer);
    }
}
