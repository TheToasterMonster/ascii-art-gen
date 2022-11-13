#include "Color.h"
#include <cmath>

Color operator*(float scalar, const Color &color) {
    return { (int)(color.r * scalar) % 256, (int)(color.g * scalar) % 256, (int)(color.b * scalar) % 256 };
}

Color operator*(const Color &color, float scalar) {
    return scalar * color;
}

Color clamp(const Color &color, uint8_t minVal, uint8_t maxVal) {
    Color result(color);

    if (result.r < minVal) result.r = minVal;

    if (result.r > maxVal) result.r = maxVal;

    if (result.g < minVal) result.g = minVal;

    if (result.g > maxVal) result.g = maxVal;

    if (result.b < minVal) result.b = minVal;

    if (result.b > maxVal) result.b = maxVal;

    return result;
}
