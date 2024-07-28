#include "SquareShader.h"

namespace GLSL {
    std::string fragmentSquare = R"(
#version 330 core

in vec2 TexCoord, VertexCord;
out vec4 FragColor;
uniform vec4 color;

void main() {
    FragColor = color;
}
)";
}