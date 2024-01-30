#include "Image.h"
#include "cassert"

Image::Image() {
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}

Image::Image(int dimensionX, int dimensionY) : dimx(dimensionX), dimy(dimensionY) {
    tab = new Pixel[dimx * dimy];
}

Image::~Image() {
    if (tab != nullptr) {
        delete[] tab;
        tab = nullptr;
    }
    dimx = 0;
    dimy = 0;
}

Pixel &Image::getPix(int x, int y) {
    assert((x >= 0 && x < dimx) && (y >= 0 && y < dimy));
    return tab[y * dimx + x];
}

Pixel Image::getPix(int x, int y) const {
    assert((x >= 0 && x < dimx) && (y >= 0 && y < dimy));
    return tab[y * dimx + x];
}

void Image::setPix(int x, int y, Pixel couleur) {
    assert((x >= 0 && x < dimx) && (y >= 0 && y < dimy));
    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur) {
    assert((Xmin >= 0 && Xmax <= dimx) && (Ymin >= 0 && Ymax <= dimy));
    for (int x = Xmin; x < Xmax; x++) {
        for (int y = Ymin; y < Ymax; y++) {
            tab[y * dimx + x] = couleur;
        }
    }
}

void Image::effacer(Pixel couleur) {
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression() {
    Image testConstructeurDef;
    int const dimensionX = 0, dimensionY = 0;
    Image testConstructeurArg(dimensionX, dimensionY);
}