#include "ColorUtils.h"

Color::Color() : red(0.0f), green(0.0f), blue(0.0f), alpha(255.0f){}
Color::Color(float r, float g, float b) : red(r), green(g), blue(b), alpha(255.0f) {}
Color::Color(int value, bool rgba) {
    if (rgba) {
        setRGBA(value);
    } else {
        setRGB(value);
    }
}
Color::Color(std::string hex) {
    setHex(hex);
}
Color::Color(int h, int s, int l) {
    setHSL(h,s,l);
}
Color::Color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {}

float Color::getRed() const {
	return red;
}
float Color::getNormalizedRed() const {
    return red / 255.0f;
}
float Color::getBlue() const {
	return blue;
}
float Color::getNormalizedBlue() const {
    return blue / 255.0f;
}
float Color::getGreen() const {
	return green ;
}
float Color::getNormalizedGreen() const {
    return green / 255.0f;
}
float Color::getAlpha() const {
    return alpha;
}
float Color::getNormalizedAlpha() const {
    return alpha / 255.0f;
}
int Color::getRGB() const {
    int r = static_cast<int>(red) & 0xFF;   
    int g = static_cast<int>(green) & 0xFF; 
    int b = static_cast<int>(blue) & 0xFF;  
    return (r << 16) | (g << 8) | b;
}
int Color::getRGBA() const {
    int r = static_cast<int>(red) & 0xFF;
    int g = static_cast<int>(green) & 0xFF; 
    int b = static_cast<int>(blue) & 0xFF;  
    int a = static_cast<int>(alpha) & 0xFF; 
    return (a << 24) | (r << 16) | (g << 8) | b;
}
void Color::setRed(float r) {
    red = r;
}
void Color::setGreen(float g) {
    green = g;
}
void Color::setBlue(float b) {
    blue = b;
}
void Color::setAlpha(float a) {
    alpha = a;
}
void Color::setHex(std::string hex) {
    if (hex.size() != 7 && hex.size() != 9) {
        std::cerr << "Invalid HEX color format." << std::endl;
        return;
    }
    std::istringstream iss(hex.substr(1));
    unsigned int hexValue;
    iss >> std::hex >> hexValue;
    red = static_cast<float>((hexValue >> 16) & 0xFF);
    green = static_cast<float>((hexValue >> 8) & 0xFF);
    blue = static_cast<float>(hexValue & 0xFF);
    if (hex.size() == 9) {
        alpha = static_cast<float>((hexValue >> 24) & 0xFF);
    }
    else {
        alpha = 255.0f;
    }
}
void Color::setRGB(int rgb) {
    int r = (rgb >> 16) & 0xFF;
    int g = (rgb >> 8) & 0xFF;
    int b = rgb & 0xFF;
    red = r;
    green = g;
    blue = b;
    alpha = 255.0f;
}
void Color::setRGBA(int rgba) {
    int r = (rgba >> 16) & 0xFF;
    int g = (rgba >> 8) & 0xFF;
    int b = rgba & 0xFF;
    int a = (rgba >> 24) & 0xFF;

    red = r;
    green = g;
    blue = b;
    alpha = a;
}

void Color::setHSL(int h, int s, int l) {
    float hNorm = h / 360.0f;  
    float sNorm = s / 100.0f;  
    float lNorm = l / 100.0f;  

    float c = (1 - std::abs(2 * lNorm - 1)) * sNorm;  
    float x = static_cast<float>(c * (1 - std::abs(std::fmod(hNorm * 6, 2) - 1)));  
    float m = lNorm - c / 2;  

    float rPrime, gPrime, bPrime;

    if (0 <= hNorm && hNorm < 1.0f / 6.0f) {
        rPrime = c;
        gPrime = x;
        bPrime = 0;
    }
    else if (1.0f / 6.0f <= hNorm && hNorm < 2.0f / 6.0f) {
        rPrime = x;
        gPrime = c;
        bPrime = 0;
    }
    else if (2.0f / 6.0f <= hNorm && hNorm < 3.0f / 6.0f) {
        rPrime = 0;
        gPrime = c;
        bPrime = x;
    }
    else if (3.0f / 6.0f <= hNorm && hNorm < 4.0f / 6.0f) {
        rPrime = 0;
        gPrime = x;
        bPrime = c;
    }
    else if (4.0f / 6.0f <= hNorm && hNorm < 5.0f / 6.0f) {
        rPrime = x;
        gPrime = 0;
        bPrime = c;
    }
    else {
        rPrime = c;
        gPrime = 0;
        bPrime = x;
    }

    
    red = clamp((rPrime + m) * 255.0f, 0.0f, 255.0f);
    green = clamp((gPrime + m) * 255.0f, 0.0f, 255.0f);
    blue = clamp((bPrime + m) * 255.0f, 0.0f, 255.0f);
    alpha = 255.0f;  
}

