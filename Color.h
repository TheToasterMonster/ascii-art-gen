#pragma once

struct Color {
    int r, g, b;
};

Color operator*(float scalar, const Color &color);
Color operator*(const Color &color, float scalar);
Color clamp(const Color &color, int minVal, int maxVal);
