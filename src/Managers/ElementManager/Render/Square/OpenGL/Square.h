#pragma once

#include <vector>
#include <string>
#include "../../../../../Render/OpenGL/Shader/ShaderHelper.h"
#include "../../Shader/GLSL/Shader/SquareShader.h"
#include "../../Shader/GLSL/Vertex/VertexShader.h"
#include "../../../../../Utils/ColorUtils/ColorUtils.h"

namespace SquareOpenGL {
	extern std::vector<unsigned int> indices;
	extern std::vector<float> defaultVector;

	void drawSquare(float x, float y, float width, float height, Color color);
}