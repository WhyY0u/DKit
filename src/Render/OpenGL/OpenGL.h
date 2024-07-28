#pragma once
#define GLFW_INCLUDE_NONE
#include <glew.h>    
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include "../../Utils/ColorUtils/ColorUtils.h"
#include <stb_image.h>
#include "../../Utils/KeyBoardUtils/KeyBoardUtils.h"
#include "../../Managers/WindowManager/WindowManager.h"


class OpenGL {
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
    void setCallBackMouseScroll(std::function<void(double, double, double, double)> callback);
    void setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack);
    void setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack);
    void setCallBackCharacter(std::function<void(std::string ch)> ch);
    void setBackgroundColor(Color color);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void cursor_position_callback(double xpos, double ypos);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset, double mouseX, double mouseY);
    void key_callback(int key, int scancode, int action, int mods, const char* name);
    void character_callback(unsigned int codepoint);
    void setMaxFPS(int max);
    void setVSync(bool action);
    void enableLimitFPS(bool action);
    int getWidth();
    int getHeight();
    GLFWwindow* getWindow();
    double getFPS();
    int getMaxFPS();
    

private:
    GLFWwindow* window;
    int width, height;
    std::function<void(double, double)> mousemove_callback;
    std::function<void(double, double, int)> mouseClickedDownCallback;
    std::function<void(double, double, int)> mouseClickedUpCallback;
    std::function<void(double, double, double, double)> mouseScrollCallBack;
    std::function<void(int key, int scancode, int action, int mods, const char* name)> keyPressedCallBack;
    std::function<void(int key, int scancode, int action, int mods, const char* name)> keyReleasedCallBack;
    std::function<void(std::string ch)> characterCallback;
    double fps;
    int maxFPS = 60;
    bool actionlimitFPS = false;
    bool actionVSync = true;

};
	
