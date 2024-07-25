#pragma once

#include <vector>
#include <string>
#include "../../../../Render/OpenGL/Shader/ShaderHelper.h"
#include "../Shader/GLSL/Shader/SquareShader.h"
#include "../Shader/GLSL/Vertex/VertexShader.h"

extern std::vector<unsigned int> indices;
void drawSquare(float x, float y, float width, float height);
