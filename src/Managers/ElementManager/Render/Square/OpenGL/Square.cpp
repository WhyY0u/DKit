#include "Square.h"

    std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
    void drawSquare(float x, float y, float width, float height) {
        ShaderInfo* info = getShaderInfo("Square", GLSL::defaultVertex, GLSL::fragmentSquare, {
           x, y, 0.0f, 0.0f, 0.0f,
           x + width, y, 0.0f, 1.0f, 0.0f,
           x + width, y + height, 0.0f, 1.0f, 1.0f,
           x, y + height, 0.0f, 0.0f, 1.0f
            }, indices);
        Shader* shader = getShader(info);
        shader->updateVector({
           x, y, 0.0f, 0.0f, 0.0f,
           x + width, y, 0.0f, 1.0f, 0.0f,
           x + width, y + height, 0.0f, 1.0f, 1.0f,
           x, y + height, 0.0f, 0.0f, 1.0f
            }, indices);
        shader->useShader();
        shader->startRender();
        shader->stopRender();
    }
