#pragma once

#include <iostream>


#ifdef _WIN32
#include "glew.h"
#include "glfw3.h"
#endif

#ifdef __linux__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif

#include "RenderAPI.h"
#include "KeyBoardUtils.h"
#include "WindowManager.h"

class OpenGL : public RenderAPI {
public:
    OpenGL();
    ~OpenGL();

    void init() override;
    void createWindow(const std::string& name, const int& width, const int& height) override;
    void destroyWindow() override;
    void mainLoop(std::function<void()> callback) override;
    void setScreenFrames(bool frames) override;
    void setWindowsIcon(const std::string &path) override;
    void setCallBackMouseMove(std::function<void(double, double)> callback) override;
    void setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) override; 
    void setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) override;
    void setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) override;
    void setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackCharacter(std::function<void(const std::string ch)> ch) override;
    void setBackgroundColor(Color color) override;
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void cursor_position_callback(double xpos, double ypos);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void scroll_callback(double xoffset, double yoffset, double mouseX, double mouseY);
    void key_callback(int key, int scancode, int action, int mods, const char* name);
    void character_callback(unsigned int codepoint);
    void setMaxFPS(int max) override;
    void setVSync(bool action) override;
    void enableLimitFPS(bool action) override;
    int getWidth() override;
    int getHeight() override;
    GLFWwindow* getWindow();
    double getFPS() override;
    int getMaxFPS() override;

private:
    GLFWwindow* window;
};
