#include "Image.h"

Image::Image() {
    dimx = 0;
    dimy = 0;
}

Image::Image(int dimensionX, int dimensionY) : dimx(dimensionX), dimy(dimensionY) {
    tab = new Pixel[dimx*dimy];
}

Image::~Image() {
    delete [] tab;
    tab = nullptr;
}

void Image::testRegression() {
    Image testConstructeurDef();
    int dimensionX = 0, dimensionY = 0;
    Image testConstructeurArg(dimensionX, dimensionY);
}