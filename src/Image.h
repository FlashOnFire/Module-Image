#ifndef _IMAGE_H
#define _IMAGE_H


#include <string>
#include "Pixel.h"

class ImageViewer;

/**
 * @class Image
 *
 * @brief Gère une image sous la forme d'un tableau de Pixels
 */
class Image {
friend ImageViewer;

private:
    Pixel* tab;
    unsigned int dimx, dimy;
public:
    /**
     * @brief Initialise dimx et dim y à 0
     * n'alloue aucune mémoire pour le tableau de pixel
     */
    Image();

    /**
     * @brief Initialise dimx et dimy (après vérification)
     * puis alloue le tableau de pixel sur le tas (image noire)
     *
     * @param dimensionX : Entier naturel
     * @param dimensionY : Entier naturel
     */
    Image(unsigned int dimensionX, unsigned int dimensionY);

    /**
     * @brief Désallocation de la mémoire du tableau de pixels et mise a jour des champs dimX et dimY à 0
     */
    ~Image();

    /**
     * @brief Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité.
     * La formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
     *
     * @param x : Entier naturel
     * @param y : Entier naturel
     * @return Pixel (l'original, pas une copie)
     */
    Pixel& getPix(unsigned int x, unsigned int y);

    /**
     * @brief Récupère le pixel original de coordonnées (x,y) en vérifiant sa validité.
     *
     * @param x : Entier naturel
     * @param y : Entier naturel
     * @return Une copie du Pixel
     */
    Pixel getPix(unsigned int x,unsigned int y) const;

    /**
     * @brief Modifie le pixel de coordonnées (x, y)
     *
     * @param x : Entier naturel
     * @param y : Entier naturel
     * @param couleur Le nouveau pixel
     */
    void setPix(unsigned int x, unsigned int y, Pixel couleur);

    /**
     * @brief Dessine un rectangle plein de la couleur dans l'image
     *
     * @param Xmin : Entier naturel
     * @param Ymin : Entier naturel
     * @param Xmax : Entier naturel
     * @param Ymax : Entier naturel
     * @param couleur : Pixel
     */
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel couleur);

    /**
     * @brief Efface l'image en la remplissant de la couleur en paramètre
     *
     * @param Xmin : Entier naturel
     * @param Ymin : Entier naturel
     * @param Xmax : Entier naturel
     * @param Ymax : Entier naturel
     * @param couleur : Pixel
     */
    void effacer(Pixel couleur);

    /**
     * @brief Sauvegarde l'instance de l'image en l'écrivant dans un fichier
     *
     * @param filename : String
     */
    void sauver(const std::string &filename) const;

    void ouvrir(const std::string &filename);

    /**
     * @brief Affiche les pixels de toute l'image dans la console
     */
    void afficherConsole();

    /**
     * @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et
     * font bien ce qu'elles sont censées faire, ainsi que les données membres de
     * l'objets sont conformes
     */
    static void testRegression();
};


#endif
