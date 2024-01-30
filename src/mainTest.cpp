#include <iostream>

#include "Pixel.h"

int main() {
    Pixel p1;
    Pixel p2(10,20,30);

    std::cout << (int) p1.r << std::endl;
    std::cout << (int) p2.b << std::endl;
}
