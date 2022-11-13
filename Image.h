#pragma once

#include <string>
#include <vector>
#include "Color.h"

typedef std::vector<std::vector<Color>> ImageData;

class Image {
  public:
    void Save(const std::string &filePath);
    const ImageData data() const {
        return m_ImageData;
    }
    Image(const std::string &filePath);
  private:
    std::string m_MagicNumber;
    int m_Width, m_Height, m_ColorRange;
    ImageData m_ImageData;
};

