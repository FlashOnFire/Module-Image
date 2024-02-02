#include <iostream>
#include "Image.h"

int main() {
    Pixel rouge(205, 9, 13);
    Pixel jaune(242, 248, 22);
    Pixel bleu(120, 193, 246);
    Image image1(3, 3);
    image1.effacer(bleu);
    image1.dessinerRectangle(0, 0, 1, 2, rouge);
    image1.setPix(1, 2, jaune);
    image1.setPix(2, 1, jaune);
    image1.afficherConsole();
    image1.sauver("./data/image1.ppm");
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.afficherConsole();
    image2.dessinerRectangle(0, 0, 1, 1, rouge);
    image2.dessinerRectangle(1, 1, 3, 3, jaune);
    image2.sauver("./data/image2.ppm");
    image2.afficherConsole();
    std::cout << "main passé ! " << std::endl;
    return 0;
}