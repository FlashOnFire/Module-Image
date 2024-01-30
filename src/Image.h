#ifndef _IMAGE_H
#define _IMAGE_H


#include "Pixel.h"

class Image {
private:
    Pixel* tab;
    int dimx, dimy;
public:
    /**
     * @brief initialise dimx et dim y à 0
     * n'alloue aucune mémoire pour le tableau de pixel
     */
    Image();

    /**
     * @brief initialise dimx et dimy (après vérification)
     * puis alloue le tableau de pixel sur le tas (image noire)
     * @param dimensionX : Entier
     * @param dimensionY : Entier
     */
    Image(int dimensionX, int dimensionY);

    /**
     * déallocation de la mémoire du tableau de pixels et mise a jour des champs dimX et dimY à 0
     */
    ~Image();

    /**
     * @brief Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité.
     * La formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
     * @param x : Entier
     * @param y : Entier
     * @return Pixel (l'original, pas une copie)
     */
    Pixel& getPix(int x, int y);

    /**
     * @brief Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité.
     * @param x : Entier
     * @param y : Entier
     * @return Pixel (une copie du Pixel)
     */
    Pixel getPix(int x, int y) const;

    /**
     * @brief Modifie le pixel de coordonnées (x, y)
     * @param x : Entier
     * @param y : Entier
     * @param couleur
     */
    void setPix(int x, int y, Pixel couleur);

    /**
     * @brief Dessine un rectangle plein de la couleur dans l'image
     * (en utilisant setPix, indices en paramètre compris)
     * @param Xmin : Entier
     * @param Ymin : Entier
     * @param Xmax : Entier
     * @param Ymax : Entier
     * @param couleur : Pixel
     */
    void dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur);

    /**
     * @brief Efface l'image en la remplissant de la couleur en paramètre
     * (en appelant dessiner Rectangle avec le bon rectangle)
     * @param couleur : Pixel
     */
    void effacer(Pixel couleur);

    /**
     * Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et
     * font bien ce qu'elles sont censées faire, ainsi que les données membres de
     * l'objets sont conformes
     */
    static void testRegression();
};


#endif
