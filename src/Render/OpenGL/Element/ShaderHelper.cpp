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
void Shader::deleteShader() {
    glDeleteVertexArrays(1, &info.VAO);
    glDeleteBuffers(1, &info.VBO);
    glDeleteBuffers(1, &info.EBO);
    glDeleteShader(info.VertexShader);
    glDeleteShader(info.FragmentShader);
    glDeleteProgram(info.ShaderProgram);
}
void Shader::updateVector(std::vector<float> v, std::vector<unsigned int> i) {
    glBindBuffer(GL_ARRAY_BUFFER, info.VBO);
    glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(float), v.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, info.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, i.size() * sizeof(int), i.data(), GL_STATIC_DRAW);
}
void Shader::useShader() {
  glUseProgram(info.ShaderProgram);
  glm::mat4 projectionMatrix = glm::ortho(0.0f, static_cast<float>(WindowManager::width), static_cast<float>(WindowManager::height), 0.0f, -1.0f, 1.0f);
  int projectionLoc = glGetUniformLocation(info.ShaderProgram, "projection");
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
void Shader::startRender() {
    glBindVertexArray(info.VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
void Shader::stopRender() {
    glUseProgram(0);
}
void Shader::setUniform1i(const std::string name, int n) {
    GLint location = glGetUniformLocation(info.ShaderProgram, name.c_str());
    glUniform1i(location, n);
}
void Shader::setUniform1f(const std::string name, float n) {
    GLint location = glGetUniformLocation(info.ShaderProgram, name.c_str());
    glUniform1f(location, n);
}
void Shader::setUniform2f(const std::string name, float n, float n2) {
    GLint location = glGetUniformLocation(info.ShaderProgram, name.c_str());
    glUniform2f(location, n, n2);
}
void Shader::setUniform3f(const std::string name, float n, float n2, float n3) {
    GLint location = glGetUniformLocation(info.ShaderProgram, name.c_str());
    glUniform3f(location, n, n2, n3);
}
void Shader::setUniform4f(const std::string name, float n, float n2, float n3, float n4) {
    GLint location = glGetUniformLocation(info.ShaderProgram, name.c_str());
    glUniform4f(location, n, n2, n3, n4);
}
