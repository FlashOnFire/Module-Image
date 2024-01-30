#include "Image.h"
#include "cassert"
#include "Pixel.h"

Image::Image() {
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}

Image::Image(const int dimensionX, const int dimensionY) : dimx(dimensionX), dimy(dimensionY) {
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

Pixel& Image::getPix(int x, int y) {
    assert(x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);

    return tab[y * dimx + x];
}

Pixel Image::getPix(int x, int y) const {
    assert(x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);

    return tab[y * dimx + x];
}

void Image::setPix(int x, int y, Pixel couleur) {
    assert(x >= 0 && x < dimx);
    assert(y >= 0 && y < dimy);

    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur) {
    assert(Xmin >= 0 && Xmax <= dimx);
    assert(Ymin >= 0 && Ymax <= dimy);

    for (int y = Ymin; y < Ymax; y++) {
        for (int x = Xmin; x < Xmax; x++) {
            tab[y * dimx + x] = couleur;
        }
    }
}

void Image::effacer(Pixel couleur) {
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression() {
    Image testConstructeurDef;
    const int dimensionX = 0;
    const int dimensionY = 0;
    Image testConstructeurArg(dimensionX, dimensionY);

    Pixel blanc(255, 255, 255);
    Pixel rouge(255, 0, 0);
    Pixel noir;

    assert(testConstructeurArg.getPix(1, 1).r == 0 && testConstructeurArg.getPix(1, 1).g == 0 &&
           testConstructeurArg.getPix(1, 1).b == 0);

    testConstructeurArg.dessinerRectangle(3, 3, 6, 6, blanc);

    assert(testConstructeurArg.getPix(5, 5).r == 255 && testConstructeurArg.getPix(5, 5).g == 255 &&
           testConstructeurArg.getPix(5, 5).b == 255);

    testConstructeurArg.effacer(noir);

    assert(testConstructeurArg.getPix(5, 5).r == 0 && testConstructeurArg.getPix(5, 5).g == 0 &&
           testConstructeurArg.getPix(5, 5).b == 0);

    testConstructeurArg.setPix(2, 2, red);

    assert(testConstructeurArg.getPix(2, 2).r == 255 && testConstructeurArg.getPix(2, 2).g == 0 &&
           testConstructeurArg.getPix(2, 2).b == 0);
}
