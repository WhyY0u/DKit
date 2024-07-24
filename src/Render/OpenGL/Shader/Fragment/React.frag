#version 330 core

in vec2 TexCoord, VertexCord;
out vec4 FragColor;

void main() {
    FragColor = vec4(vec3(1.0,0.0,0.0), 1.0);
}