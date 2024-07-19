#include <iostream>
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
Color color = Color(65280, false);

void Render();

int main() {
	opengl.init();
	opengl.createWindow("DKit", 290, 255);
	opengl.setScreenFrames(false);
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	opengl.setBackgroundColor(color);
}