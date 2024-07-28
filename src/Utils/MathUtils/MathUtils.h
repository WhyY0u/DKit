#ifndef MATH_UTILS_H
#define MATH_UTILS_H
template <typename T>
T clamp(T value, T min, T max) {
    return (value < min) ? min : (value > max) ? max : value;
}
#endif