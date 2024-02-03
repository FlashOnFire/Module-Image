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
    const int imageWidth = static_cast<int>(im.dimx);
    const int imageHeight = static_cast<int>(im.dimy);

    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }

    Uint32 redMask, greenMask, blueMask, alphaMask;
    int bytesPerPixel;
    SDL_PixelFormatEnumToMasks(SDL_PixelFormatEnum::SDL_PIXELFORMAT_RGB24, &bytesPerPixel, &redMask, &greenMask, &blueMask, &alphaMask);

    surface = SDL_CreateRGBSurfaceFrom(im.tab, imageWidth, imageHeight, bytesPerPixel,
                                       imageWidth * 3, redMask, greenMask, blueMask, alphaMask);

    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    bool running = true;
    int windowWidth;
    int windowHeight;

    float zoom = 1.0f;
    SDL_Rect dstRect;

    SDL_Event e;

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
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

        SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

        dstRect.w = static_cast<int>(static_cast<float>(imageWidth) * zoom);
        dstRect.h = static_cast<int>(static_cast<float>(imageHeight) * zoom);
        dstRect.x = static_cast<int>(windowWidth / 2.0 - dstRect.w / 2.0);
        dstRect.y = static_cast<int>(windowHeight / 2.0 - dstRect.h / 2.0);

        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
        SDL_RenderPresent(renderer);
    }
}
