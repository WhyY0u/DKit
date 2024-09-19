#pragma once
#ifndef SHADERHELPER_H
#define SHADERHELPER_H

#ifdef _WIN32
#include "glew.h"
#endif

#ifdef __linux__
#include <GL/glew.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <memory> 
#include "../../../Managers/WindowManager/WindowManager.h"

struct ShaderInfo {
	std::string name;
	std::string Vertex;
	std::string Shader;
	std::vector<float> vectors;
    std::vector<float> second_vectors;
	std::vector<unsigned int> index;
    std::vector<unsigned int> second_index;

	GLuint VertexShader, FragmentShader, ShaderProgram;
	GLuint VAO, VBO, EBO;
	GLuint textureID;
    GLuint instanceVBO;
};
class Shader {
public:
    Shader() {};
    Shader(ShaderInfo* info) : info(info) {}
	ShaderInfo* getInfo();
    void setShaderInfo(ShaderInfo* i);
    void initInstancing();
	void initShader();
    void deleteShader();
    void updateVector();
    void useShader();
    void startRender();
    void stopRender();
    void setUniform1i(const std::string name, int n);
    void setUniform1f(const std::string name, float n);
    void setUniform2f(const std::string name, float n, float n2);
    void setUniform3f(const std::string name, float n, float n2, float n3);
    void setUniform4f(const std::string name, float n, float n2, float n3, float n4);

private:
	ShaderInfo* info;
    bool init;
    const bool compileShader(GLuint& shader, GLenum type, const char* source) {
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
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
        GLchar infoLog[512];
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(programID, 512, nullptr, infoLog);
            std::cerr << "Shader program linking failed: " << infoLog << std::endl;
            return false;
        }
        return true;
    }
};
void setShaderInfo(ShaderInfo& info, std::string name, std::string Vertex, std::string Shader);
void setShaderInfoVector(ShaderInfo& info, std::vector<float> vectors, std::vector<unsigned int> index);
static std::unordered_map<std::string, std::unique_ptr<Shader>>& getShaderCache() {
    static std::unordered_map<std::string, std::unique_ptr<Shader>> shaders;
    return shaders;
}
static std::unordered_map<std::string, std::unique_ptr<ShaderInfo>>& getShaderInfoCache() {
    static std::unordered_map<std::string, std::unique_ptr<ShaderInfo>> shaders;
    return shaders;
}
static ShaderInfo* getShaderInfo(std::string name, std::string VertexShader, std::string FragmentShader, std::vector<float> vectors, std::vector<unsigned int> index) {
    auto& infos = getShaderInfoCache();
    auto it = infos.find(name);
    if (it != infos.end()) {
        auto& info = it->second;
        return info.get();
    }
    auto info = std::make_unique<ShaderInfo>();
    info->name = name;
    info->Vertex = VertexShader;
    info->Shader = FragmentShader;
    info->vectors = vectors;
    info->index = index;
    infos[name] = std::move(info);

    return infos[name].get();
}
static Shader* getShader(ShaderInfo* info) {
    auto& shaders = getShaderCache();
    auto it = shaders.find(info->name);
    if (it != shaders.end()) {
        return it->second.get();
    }
    auto shader = std::make_unique<Shader>();
    shader->setShaderInfo(info);
    shaders[info->name] = std::move(shader);

    return shaders[info->name].get();
}

#endif
