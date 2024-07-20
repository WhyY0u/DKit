#include <iostream>
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
Color color = Color(65280, false);

void Render();
void MouseMove(double X, double Y);

int main() {
	opengl.init();
	opengl.createWindow("DKit", 290, 255);
	opengl.setScreenFrames(false);
	opengl.setWindowsIcon("C:/Users/User/Downloads/background.png");
	opengl.setCallBackMouseMove(MouseMove);
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	opengl.setBackgroundColor(color);
}

void MouseMove(double X, double Y) {
	std::cout << "X: " << X << "Y: " << Y << std::endl;
}