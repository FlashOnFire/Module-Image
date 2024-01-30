#include "Image.h"

Image::Image() {
    dimx = 0;
    dimy = 0;
}

Image::Image(int dimensionX, int dimensionY) : dimx(dimensionX), dimy(dimensionY) {
    tab = new Pixel[dimx * dimy];
}

Image::~Image() {
    delete[] tab;
    tab = nullptr;
    dimx = 0;
    dimy = 0;
}

Pixel &Image::getPix(int x, int y) {
    return tab[y * dimx + x];
}

Pixel Image::getPix(int x, int y) const {
    return tab[y * dimx + x];
}

void Image::setPix(int x, int y, Pixel couleur) {
    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur) {
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