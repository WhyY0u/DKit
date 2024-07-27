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
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        return true;
    }
void OpenGL::setScreenFrames(bool frames) {
    glfwSetWindowAttrib(window, GLFW_DECORATED, frames);
}
void OpenGL::setWindowsIcon(std::string path) {
    int width, height, channels;
    unsigned char* imgData = stbi_load(path.c_str(), &width, &height, &channels, 4);
    if (!imgData) {
        std::cerr << "Failed to load icon image" << std::endl;
        glfwTerminate();
        return;
    }

    GLFWimage image;
    image.pixels = imgData;
    image.width = width;
    image.height = height;

    glfwSetWindowIcon(window, 1, &image);

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
void OpenGL::setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) {
    mouseScrollCallBack = callback;
    glfwSetScrollCallback(window, [](GLFWwindow* win, double xoffset, double yoffset) {
        double mouseX, mouseY;
        glfwGetCursorPos(win, &mouseX, &mouseY);
        static_cast<OpenGL*>(glfwGetWindowUserPointer(win))->scroll_callback(xoffset, yoffset, mouseX, mouseY);
        });
}
void OpenGL::setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
    keyPressedCallBack = callback;
}
void OpenGL::setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
    keyReleasedCallBack = callback;
}
void OpenGL::setCallBackCharacter(std::function<void(std::string ch)> ch) {
    characterCallback = ch;
}
void OpenGL::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    mouseClickedUpCallback = callback;
}
void OpenGL::setBackgroundColor(Color color) {
    glClearColor(color.getNormalizedRed(), color.getNormalizedGreen(), color.getNormalizedBlue(), color.getNormalizedAlpha());
}
void OpenGL::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
   glViewport(0, 0, width, height);
   WindowManager::setScreenSize(width, height);
}
void OpenGL::cursor_position_callback(double xpos, double ypos) {
    if (mousemove_callback) {
        mousemove_callback(xpos, ypos);
    }
}
void OpenGL::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (mouseClickedDownCallback) {
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            mouseClickedDownCallback(x, y, button);
        }
    }

    if (action == GLFW_RELEASE) {
        if (mouseClickedDownCallback) {
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            mouseClickedUpCallback(x, y, button);
        }
    }
}
void OpenGL::scroll_callback(double xoffset, double yoffset, double mouseX, double mouseY) {
    if (mouseScrollCallBack) {
        mouseScrollCallBack(xoffset, yoffset, mouseX, mouseY);
    }
}
void OpenGL::key_callback(int key, int scancode, int action, int mods, const char* name) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (keyPressedCallBack) {
            keyPressedCallBack(key, scancode, action, mods, name);
        }
    }
    if (action == GLFW_RELEASE) {
        if (keyReleasedCallBack) {
            keyReleasedCallBack(key, scancode, action, mods, name);
        }
    }
}
void OpenGL::character_callback(unsigned int codepoint) {
    if (characterCallback) {
        characterCallback(codepoint_to_utf8(codepoint));
    }
}
void OpenGL::setMaxFPS(int max) {
    maxFPS = max;
}
int OpenGL::getWidth() {
 return OpenGL::width;
}
int OpenGL::getHeight() {
return OpenGL::height;
}
void OpenGL::setVSync(bool action) {
    if (action != actionVSync) {
        glfwSwapInterval(action ? 1 : 0);
        actionVSync = action;
        if (action) {
            actionlimitFPS = false;
        }
    }
}
GLFWwindow* OpenGL::getWindow() {
return OpenGL::window;
}
void OpenGL::enableLimitFPS(bool action) {
    actionlimitFPS = action;
}
double OpenGL::getFPS() {
    return fps;
}
int OpenGL::getMaxFPS() {
    return maxFPS;
}
void OpenGL::createWindow(const std::string& name, const int& width, const int& height) {
        if (OpenGL::window) {
            return;
        }
        OpenGL::width = width;
        OpenGL::height = height;
        WindowManager::setScreenSize(width, height);
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

        glfwSetFramebufferSizeCallback(OpenGL::window, OpenGL::framebuffer_size_callback);


        glfwMakeContextCurrent(OpenGL::window);

        glewExperimental = GL_TRUE; 
        if (glewInit() != GLEW_OK) {
            std::cerr << "Failed to initialize GLEW" << std::endl;
            return;
        }
        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
        std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
        glfwSetMouseButtonCallback(window, [](GLFWwindow* win, int button, int action, int mods) {
            static_cast<OpenGL*>(glfwGetWindowUserPointer(win))->mouse_button_callback(win, button, action, mods);
            });
        glfwSetKeyCallback(window, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
            const char* keyName = glfwGetKeyName(key, scancode);
            static_cast<OpenGL*>(glfwGetWindowUserPointer(win))->key_callback(key, scancode, action, mods, keyName ? keyName : "NULL");
            });
        glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int codepoint) {
            static_cast<OpenGL*>(glfwGetWindowUserPointer(window))->character_callback(codepoint);
            });

        glViewport(0, 0,width, height);
       
    }
void OpenGL::destroyWindow() {
        if (OpenGL::window) {
            glfwDestroyWindow(OpenGL::window);
        }
        glfwTerminate();
    }
void OpenGL::mainLoop(std::function<void()> callback) {
    double lastTime = glfwGetTime();
    int frameCount = 0;
    double fpsTimer = 0.0;
    while (!glfwWindowShouldClose(window)) {
        double targetFrameTime = 1.0 / maxFPS;
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        glfwPollEvents();
        if (actionlimitFPS && deltaTime < targetFrameTime) {
            double sleepTime = (targetFrameTime - deltaTime) * 1000.0; 
            continue; 
        }
        lastTime = currentTime;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        callback();
        glfwSwapBuffers(window);
        frameCount++;
        fpsTimer += deltaTime;
        if (fpsTimer >= 1.0) {
            fps = frameCount / fpsTimer;
            frameCount = 0;
            fpsTimer = 0.0;
        }
    }
}
