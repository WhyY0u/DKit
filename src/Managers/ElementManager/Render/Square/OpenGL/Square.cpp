#include "Square.h"


namespace SquareOpenGL {
    std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
    std::vector<float> defaultVector = {
   0, 0, 0.0f, 0.0f, 0.0f,
   0 + 0, 0, 0.0f, 1.0f, 0.0f,
   0 + 0, 0 + 0, 0.0f, 1.0f, 1.0f,
   0, 0 + 0, 0.0f, 0.0f, 1.0f
    };

    ShaderInfo* infoDefaultSquare = getShaderInfo("Square", GLSL::defaultVertex, GLSL::fragmentSquare, defaultVector, indices);
    Shader* shaderDefaultSquare = getShader(infoDefaultSquare);

    void drawSquare(float x, float y, float width, float height, Color color) {
        shaderDefaultSquare->initShader();
        infoDefaultSquare->second_vectors = {
           x, y, 0.0f, 0.0f, 0.0f,
           x + width, y, 0.0f, 1.0f, 0.0f,
           x + width, y + height, 0.0f, 1.0f, 1.0f,
           x, y + height, 0.0f, 0.0f, 1.0f
        };
        infoDefaultSquare->second_index = indices;
        shaderDefaultSquare->updateVector();
        shaderDefaultSquare->useShader();
        shaderDefaultSquare->setUniform4f("color", color.getNormalizedRed(), color.getNormalizedGreen(), color.getNormalizedBlue(), color.getNormalizedAlpha());
        shaderDefaultSquare->startRender();
        shaderDefaultSquare->stopRender();
    }
}