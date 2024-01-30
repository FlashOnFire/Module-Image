#ifndef _PIXEL_H
#define _PIXEL_H


struct Pixel {
    unsigned char r, g, b;

    /**
     * @brief Constructeur par défaut de la classe:
     * initialise le pixel à la couleur noire
     */
    Pixel() : r(0), g(0), b(0) {
    };

    /**
     * @brief Constructeur de la classe:
     * initialise r,g,b avec les paramètres
     * @param nr : Entier entre 0 et 255
     * @param ng : Entier entre 0 et 255
     * @param nb : Entier entre 0 et 255
     */
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb) : r(nr), g(ng), b(nb) {
    };
};


#endif
