#pragma once
#include <glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <iostream>

struct ShaderInfo {
	std::string name;
	std::string info;
	std::string Vertex;
	std::string Shader;
	std::vector<float> vectors;
	std::vector<unsigned int> index;
	GLuint VertexShader, FragmentShader, ShaderProgram;
	GLuint VAO, VBO, EBO;
	GLuint textureID;
};
class Shader {
	
public:
	ShaderInfo getInfo();
	void initShader();
private:
	ShaderInfo info;
    const bool compileShader(GLuint& shader, GLenum type, const char* source) {
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            GLchar infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader compilation failed: " << infoLog << std::endl;
            return false;
        }
        return true;
    }
    const bool linkProgram(GLuint& programID, GLuint vertexShader, GLuint fragmentShader) {
        programID = glCreateProgram();
        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);

        GLint success;
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success) {
            GLchar infoLog[512];
            glGetProgramInfoLog(programID, 512, nullptr, infoLog);
            std::cerr << "Shader program linking failed: " << infoLog << std::endl;
            return false;
        }
        return true;
    }

};