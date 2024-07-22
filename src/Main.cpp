#include <iostream>
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
Color color = Color(255.0f, 0.0f, 0.0f, 255.0f);

void Render();


int main() {
	opengl.init();
	opengl.createWindow("DKit", 290, 255);
	opengl.setScreenFrames(true);
	opengl.setWindowsIcon("C:/Users/User/Downloads/background.png");
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	opengl.setBackgroundColor(color);
	std::cout << opengl.getFPS() << std::endl;
}
