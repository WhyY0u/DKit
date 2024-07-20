#pragma once
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <functional>
#include "../../Utils/ColorUtils/ColorUtils.h"
#include <stb_image.h>

#ifdef _WIN32
#ifdef BUILDING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else
#define DLL_API
#endif

class DLL_API OpenGL {
public:
    OpenGL();
    ~OpenGL();

    bool init();
    void createWindow(const std::string& name, const int& width, const int& height);
    void destroyWindow();
    void mainLoop(std::function<void()> callback);
    void setScreenFrames(bool frames);
    void setWindowsIcon(std::string path);
    void setCallBackMouseMove(std::function<void(double, double)>);
    void setCallBackMouseClickedUp(std::function<void(double, double, int)> callback);
    void setCallBackMouseClickedDown(std::function<void(double, double, int)> callback);
    void setBackgroundColor(Color color);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void cursor_position_callback(double xpos, double ypos);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    int getWidth();
    int getHeight();
    GLFWwindow* getWindow();

private:
    GLFWwindow* window;
    int width, height;
    std::function<void(double, double)> mousemove_callback;
    std::function<void(double, double, int)> mouseClickedDownCallback;
    std::function<void(double, double, int)> mouseClickedUpCallback;

};
	
