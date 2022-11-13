#include "Image.h"

#include <vector>
#include <iostream>
#include <fstream>

typedef std::vector<std::vector<int>> OpacityData;
typedef std::vector<std::vector<char>> AsciiArt;

class AsciiConverter {
  public:
    static void convertAndSave(const Image &image, const std::string &fp);
    static AsciiArt convert(const Image &image);
  private:
    static OpacityData toOpacities(const Image &image);
  private:
    static constexpr int s_AsciiTableSize = 4;
    static constexpr char s_AsciiTable[s_AsciiTableSize] = {
        '.', ';', 'X', '@'
    };
};
