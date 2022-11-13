#include "AsciiConverter.h"

void AsciiConverter::convertAndSave(const Image &image, const std::string &fp) {
    std::ofstream outputFile(fp);

    if (!outputFile.is_open()) {
        std::cout << "Failed to open " << fp << ".\n";
        throw;
    }

    for (const auto &row : convert(image)) {
        for (char c : row) {
            outputFile << c;
        }
        outputFile << '\n';
    }
    outputFile.close();
};

AsciiArt AsciiConverter::convert(const Image &image) {
    OpacityData opacities = toOpacities(image);
    AsciiArt chars(opacities.size() / 2, std::vector<char>(opacities[0].size()));

    for (int i = 0; i < chars.size(); i++) {
        for (int j = 0; j < chars[0].size(); j++) {
            float avgOpacity = (opacities[2*i][j] + opacities[2*i + 1][j]) / 2.0f;
            chars[i][j] = s_AsciiTable[(int)(avgOpacity * 4 / 256)];
        }
    }

    return chars;
}

OpacityData AsciiConverter::toOpacities(const Image &image) {
    const ImageData data = image.data();
    OpacityData opacities(data.size(), std::vector<int>(data[0].size()));

    for (int i = 0; i < opacities.size(); i++) {
        for (int j = 0; j < opacities[0].size(); j++) {
            opacities[i][j] = (data[i][j].r + data[i][j].g + data[i][j].b) / 3.0f;
        }
    }

    return opacities;
}
