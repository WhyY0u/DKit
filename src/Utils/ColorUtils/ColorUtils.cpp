#include "ColorUtils.h"

Color::Color() : red(0.0f), green(0.0f), blue(0.0f), alpha(255.0f){}
Color::Color(float r, float g, float b) : red(r), green(g), blue(b), alpha(255.0f) {}
Color::Color(int rgb) {
    setRGB(rgb);
}
Color::Color(unsigned int rgba) {
    setRGBA(rgba);
}
Color::Color(std::string hex) {
    setHex(hex);
}
Color::Color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {}


float Color::getRed() const {
	return red;
}
float Color::getBlue() const {
	return blue;
}
float Color::getGreen() const {
	return green ;
}
float Color::getAlpha() const {
    return alpha;
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
    Color::red = r;
}
void Color::setGreen(float g) {
    Color::green = green;
}
void Color::setBlue(float b) {
    Color::blue = b;
}
void Color::setAlpha(float a) {
    Color::alpha = a;
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
    blue = static_cast<float>(hexValue & 0xFF) / 255.0f;
    if (hex.size() == 9) {
        alpha = static_cast<float>((hexValue >> 24) & 0xFF);
    }
    else {
        alpha = 255.0f;
    }
}
void Color::setRGB(int rgb) {
    int red = (rgb >> 16) & 0xFF;
    int green = (rgb >> 8) & 0xFF;
    int blue = rgb & 0xFF;
    Color::setRed(red);
    Color::setGreen(green);
    Color::setBlue(red);
    Color::setAlpha(255.0f);
}
void Color::setRGBA(int rgba) {
    int red = (rgba >> 16) & 0xFF;
    int green = (rgba >> 8) & 0xFF;
    int blue = rgba & 0xFF;
    int alpha = (rgba >> 24) & 0xFF;

    Color::setRed(red);
    Color::setGreen(green);
    Color::setBlue(red);
    Color::setAlpha(alpha);
}

