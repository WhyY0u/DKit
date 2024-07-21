#include <iostream>
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
Color color = Color(255.0f, 0.0f, 0.0f, 0.0f);

void Render();
void MouseMove(double X, double Y);
void MouseClickedDown(double x, double y, int button);
void MouseClickedUp(double x, double y, int button);
void MouseScroll(double xoffset, double yoffset, double xPos, double yPos);
void KeyPressed(int key, int scancode, int action, int mods, const char* name);
void KeyReleased(int key, int scancode, int action, int mods, const char* name);

int main() {
	opengl.init();
	opengl.createWindow("DKit", 290, 255);
	opengl.setScreenFrames(false);
	opengl.setWindowsIcon("C:/Users/User/Downloads/background.png");
	opengl.setCallBackMouseMove(MouseMove);
	opengl.setCallBackMouseClickedDown(MouseClickedDown);
	opengl.setCallBackMouseClickedUp(MouseClickedUp);
	opengl.setCallBackMouseScroll(MouseScroll);
	opengl.setCallBackKeyPressed(KeyPressed);
	opengl.setCallBackKeyReleased(KeyReleased);
	opengl.mainLoop(Render);
	opengl.destroyWindow();
}

void Render() {
	opengl.setBackgroundColor(color);
}

void MouseScroll(double xoffset, double yoffset, double xPos, double yPos) {
	std::cout << " xoffset: " << xoffset << " yoffset: " << yoffset << " xPos: " << xPos << " yPos" << yPos << std::endl;
}

void MouseMove(double X, double Y) {
	std::cout << "X: " << X << "Y: " << Y << std::endl;
}
void MouseClickedDown(double x, double y, int button) {
	std::cout << "X: " << x << "Y: " << y << "button: " << button << " Down" << std::endl;
}
void MouseClickedUp(double x, double y, int button) {
	std::cout << " X: " << x << " Y: " << y << " button: " << button << " UP" << std::endl;
}
void KeyPressed(int key, int scancode, int action, int mods, const char* name) {
	std::cout << key << " Press" << std::endl;
}
void KeyReleased(int key, int scancode, int action, int mods, const char* name) {
	std::cout << key << " Released" << std::endl;
}