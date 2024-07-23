#include <iostream>
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
Color color = Color(255.0f, 0.0f, 0.0f, 255.0f);

void Render();

int main() {
	opengl.init();
	opengl.createWindow("DKit", 1280, 920);
	opengl.setScreenFrames(true);
	opengl.setWindowsIcon("C:/Users/User/Downloads/background.png");
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	opengl.setVSync(false);
	opengl.setBackgroundColor(color);
	opengl.setMaxFPS(160);
	opengl.enableLimitFPS(true);
	std::cout << opengl.getFPS() << std::endl;
}
