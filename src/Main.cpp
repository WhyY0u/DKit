#include <iostream>
#include "Render/OpenGL/OpenGL.h"
#include "Managers/ElementManager/Render/Square/OpenGL/Square.h"
OpenGL opengl = OpenGL();
Color color = Color(0.0f, 0.0f, 0.0f, 255.0f);

void Render();

int main() {
	opengl.init();
	opengl.createWindow("DKit", 1280, 920);
	opengl.setScreenFrames(true);
	opengl.setVSync(false);
	opengl.setWindowsIcon("C:/Users/User/Downloads/background.png");
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	for (int i = 0; i < 300; i++) {
		drawSquare(0.0, 0.0f, 100.0f, 100.0f);
	}
	std::cout << opengl.getFPS() << std::endl;
}
