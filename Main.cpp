#include <iostream>
#include "AsciiConverter.h"

int main() {
    Image image("images/keqing.ppm");
    AsciiConverter::convertAndSave(image, "images/output/keqing.txt");
    std::system("open images/output/keqing.txt");
}
