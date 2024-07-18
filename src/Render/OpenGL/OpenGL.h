#pragma once
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <functional>
#include "../../Utils/ColorUtils/ColorUtils.h"

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
    void setBackgroundColor(Color color);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    int getWidth();
    int getHeight();
    GLFWwindow* getWindow();

private:
    GLFWwindow* window;
    int width, height;
};
	
