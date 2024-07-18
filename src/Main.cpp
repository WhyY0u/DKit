#include <iostream>
#include "Render/OpenGL/OpenGL.h"

void Render();

int main() {
	OpenGL opengl = OpenGL();
	opengl.init();
	opengl.createWindow("DKit", 1280, 920);
	opengl.setScreenFrames(false);
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}