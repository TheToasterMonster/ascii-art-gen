#include "Image.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void Image::Save(const std::string &filePath) {
    std::filesystem::create_directory("images/output");
    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        std::cout << "Failed to open " << filePath << ".\n";
        throw;
    }

    outputFile << m_MagicNumber << '\n';
    outputFile << m_Width << " " << m_Height << '\n';
    outputFile << m_ColorRange << '\n';

    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++) {
            outputFile << m_ImageData[i][j].r << " " << m_ImageData[i][j].g << " " << m_ImageData[i][j].b << '\n';
        }
    }

    outputFile.close();
    std::cout << "Image saved." << '\n';
}

Image::Image(const std::string &filePath) {
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cout << "Failed to open " << filePath << ".\n";
        throw;
    }

    inputFile >> m_MagicNumber;
    inputFile >> m_Width >> m_Height >> m_ColorRange;
    m_ImageData = ImageData(m_Height);

    for (int i = 0; i < m_Height; i++) {
        m_ImageData[i].resize(m_Width);
    }

    for (int i = 0; i < m_Height; i++) {
        for (int j = 0; j < m_Width; j++) {
            inputFile >> m_ImageData[i][j].r >> m_ImageData[i][j].g >> m_ImageData[i][j].b;
        }
    }

    inputFile.close();
    std::cout << "Image loaded." << '\n';
}
