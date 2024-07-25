#include "Square.h"

std::vector<unsigned int> indices;

void drawSquare(float x, float y, float width, float height) {
    std::string squareName = "Square_" + std::to_string(x) + "_" + std::to_string(y) + "_" + std::to_string(width) + "_" + std::to_string(height);
	ShaderInfo* info = getShaderInfo(squareName, GLSL::defaultVertex, GLSL::fragmentSquare, {
      x, y, 0.0f, 0.0f, 0.0f,
      x + width, y, 0.0f, 1.0f, 0.0f,
      x + width,  y + height, 0.0f, 1.0f, 1.0f,
      x, y + height, 0.0f, 0.0f, 1.0f
        }, indices);
	Shader* shader = getShader(info);
    shader->updateVector({
      x, y, 0.0f, 0.0f, 0.0f,
      x + width, y, 0.0f, 1.0f, 0.0f,
      x + width,  y + height, 0.0f, 1.0f, 1.0f,
      x, y + height, 0.0f, 0.0f, 1.0f
        }, indices);
    shader->useShader();
    shader->startRender();
    shader->stopRender();
} 
