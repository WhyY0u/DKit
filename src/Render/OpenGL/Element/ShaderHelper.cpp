#include "ShaderHelper.h"

ShaderInfo Shader::getInfo() {
	return info;
}

void Shader::initShader() {
    info.VertexShader = glCreateShader(GL_VERTEX_SHADER);
    info.FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* vertexShaderSource = info.Vertex.c_str();
    const char* fragmentShaderSource = info.Vertex.c_str();

    if (!compileShader(info.VertexShader, GL_VERTEX_SHADER, vertexShaderSource) ||
        !compileShader(info.FragmentShader, GL_FRAGMENT_SHADER, fragmentShaderSource) ||
        !linkProgram(info.ShaderProgram, info.VertexShader, info.FragmentShader)) {
        std::cerr << "Shader creation failed!" + info.name << std::endl;
        info.ShaderProgram = 0;
    }
    delete vertexShaderSource;
    delete fragmentShaderSource;
    glDeleteShader(info.VertexShader);
    glDeleteShader(info.FragmentShader);
    glGenVertexArrays(1, &info.VAO);
    glGenBuffers(1, &info.VBO);
    glGenBuffers(1, &info.EBO);
    glBindVertexArray(info.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, info.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * info.vectors.size(), info.vectors.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, info.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * info.index.size(), info.index.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
