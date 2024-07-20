#include <iostream>
#include "OpenGL.h"

OpenGL::OpenGL() : window(nullptr), width(0), height(0) {}
OpenGL::~OpenGL() {
    destroyWindow();
}
bool OpenGL::init() {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return false;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        return true;
    }
void OpenGL::setScreenFrames(bool frames) {
    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);
}
void OpenGL::setWindowsIcon(std::string path) {
    int width, height, channels;
    unsigned char* imgData = stbi_load(path.c_str(), &width, &height, &channels, 4);
    if (!imgData) {
        std::cerr << "Failed to load icon image" << std::endl;
        glfwTerminate();
        return;
    }

    GLFWimage images[1];
    images[0].pixels = imgData;
    images[0].width = width;
    images[0].height = height;

    glfwSetWindowIcon(window, 1, images);

    stbi_image_free(imgData);
}
void OpenGL::setCallBackMouseMove(std::function<void(double, double)> callback) {
    mousemove_callback = callback;
    glfwSetCursorPosCallback(window, [](GLFWwindow* win, double xpos, double ypos) {
        static_cast<OpenGL*>(glfwGetWindowUserPointer(win))->cursor_position_callback(xpos, ypos);
        });
}
void OpenGL::setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) {
    mouseClickedDownCallback = callback;
}
void OpenGL::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    mouseClickedUpCallback = callback;
}
void OpenGL::setBackgroundColor(Color color) {
    glClearColor(color.getNormalizedRed(), color.getNormalizedGreen(), color.getNormalizedBlue(), color.getNormalizedAlpha());
}
void OpenGL::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
   glViewport(0, 0, width, height);
}
void OpenGL::cursor_position_callback(double xpos, double ypos) {
    if (mousemove_callback) {
        mousemove_callback(xpos, ypos);
    }
}
int OpenGL::getWidth() {
 return OpenGL::width;
}
int OpenGL::getHeight() {
return OpenGL::height;
}
GLFWwindow* OpenGL::getWindow() {
return OpenGL::window;
}
void OpenGL::createWindow(const std::string& name, const int& width, const int& height) {
        if (OpenGL::window) {
            return;
        }
        OpenGL::width = width;
        OpenGL::height = height;
        OpenGL::window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
        if (!OpenGL::window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            OpenGL::window = nullptr;
            return;
        }

        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        int windowPosX = (mode->width - width) / 2;
        int windowPosY = (mode->height - height) / 2;

        glfwSetWindowPos(window, windowPosX, windowPosY);
        glfwSetWindowUserPointer(window, this);
        glfwMakeContextCurrent(OpenGL::window);
        glfwSetFramebufferSizeCallback(OpenGL::window, OpenGL::framebuffer_size_callback);

        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            return;
        }
    }
void OpenGL::destroyWindow() {
        if (OpenGL::window) {
            glfwDestroyWindow(OpenGL::window);
        }
        glfwTerminate();
    }
void OpenGL::mainLoop(std::function<void()> callback) {
        while (!glfwWindowShouldClose(OpenGL::window)) {
            glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
            callback();
            glfwSwapBuffers(OpenGL::window);
            glfwPollEvents();
        }
    
}
