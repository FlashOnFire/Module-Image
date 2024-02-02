#include <iostream>
#include <fstream>
#include "Image.h"
#include "cassert"
#include "Pixel.h"
#include "iostream"

Image::Image() {
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}

Image::Image(const unsigned int dimensionX, const unsigned int dimensionY) : dimx(dimensionX), dimy(dimensionY) {
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

Pixel& Image::getPix(unsigned int x, unsigned int y) {
    assert(x < dimx);
    assert(y < dimy);

    return tab[y * dimx + x];
}

Pixel Image::getPix(unsigned int x, unsigned int y) const {
    assert(x < dimx);
    assert(y < dimy);

    return tab[y * dimx + x];
}

void Image::setPix(unsigned int x, unsigned int y, Pixel couleur) {
    assert(x < dimx);
    assert(y < dimy);

    tab[y * dimx + x] = couleur;
}

void
Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel couleur) {
    assert(Xmax <= dimx);
    assert(Ymax <= dimy);

    for (unsigned int y = Ymin; y < Ymax; y++) {
        for (unsigned int x = Xmin; x < Xmax; x++) {
            setPix(x, y, couleur);
        }
    }
}

void Image::effacer(Pixel couleur) {
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::sauver(const std::string& filename) const {
    std::ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << std::endl;
    fichier << dimx << " " << dimy << std::endl;
    fichier << "255" << std::endl;
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x) {
            Pixel pix = getPix(x, y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    std::cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const std::string& filename) {
    std::ifstream fichier(filename.c_str());
    assert(fichier.is_open());
    char r, g, b;
    std::string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);

    if (tab != nullptr) {
        delete[] tab;
    }

    tab = new Pixel[dimx * dimy];
    for (unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            fichier >> r >> g >> b;
            setPix(x, y, Pixel(r, g, b));
        }
    }

    fichier.close();
    std::cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole() {
    std::cout << dimx << " " << dimy << std::endl;
    for (unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            Pixel& pix = getPix(x, y);
            pix.afficherPixel();
        }
        std::cout << std::endl;
    }
}


void Image::testRegression() {
    Image testConstructeurDef;
    const int dimensionX = 30;
    const int dimensionY = 30;
    Image testConstructeurArg(dimensionX, dimensionY);

    assert(testConstructeurArg.dimx == dimensionX);
    assert(testConstructeurArg.dimy == dimensionY);

    Pixel blanc(255, 255, 255);
    Pixel rouge(255, 0, 0);
    Pixel noir;

    assert(testConstructeurArg.getPix(1, 1).r == 0);
    assert(testConstructeurArg.getPix(1, 1).g == 0);
    assert(testConstructeurArg.getPix(1, 1).b == 0);

    testConstructeurArg.dessinerRectangle(3, 3, 6, 6, blanc);

    assert(testConstructeurArg.getPix(5, 5).r == 255);
    assert(testConstructeurArg.getPix(5, 5).g == 255);
    assert(testConstructeurArg.getPix(5, 5).b == 255);

    testConstructeurArg.effacer(noir);

    assert(testConstructeurArg.getPix(5, 5).r == 0);
    assert(testConstructeurArg.getPix(5, 5).g == 0);
    assert(testConstructeurArg.getPix(5, 5).b == 0);

    testConstructeurArg.setPix(2, 2, rouge);

    assert(testConstructeurArg.getPix(2, 2).r == 255);
    assert(testConstructeurArg.getPix(2, 2).g == 0);
    assert(testConstructeurArg.getPix(2, 2).b == 0);

    std::cout << "Test de régression ok !" << std::endl;
}
