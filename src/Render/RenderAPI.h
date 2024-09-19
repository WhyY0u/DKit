#ifndef RENDERAPI_H
#define RENDERAPI_H
#include <string>
#include <functional>
#include "ColorUtils.h"
#include <stb_image.h>

class RenderAPI {
public:
RenderAPI() = default;
virtual ~RenderAPI() = default;
virtual void init();
virtual void createWindow(const std::string& name, const int& width, const int& height);
virtual void destroyWindow();
virtual void mainLoop(std::function<void()> callback);
virtual void setScreenFrames(bool frames);
virtual void setWindowsIcon(const std::string& path);
virtual void setCallBackMouseMove(std::function<void(double, double)> callback);
virtual void setCallBackMouseClickedUp(std::function<void(double, double, int)> callback);
virtual void setCallBackMouseClickedDown(std::function<void(double, double, int)> callback);
virtual void setCallBackMouseScroll(std::function<void(double, double, double, double)> callback);
virtual void setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback);
virtual void setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback);
virtual void setCallBackCharacter(std::function<void(const std::string ch)> ch);
virtual void setBackgroundColor(Color color);
virtual void setMaxFPS(int max);
virtual void setVSync(bool action);
virtual void enableLimitFPS(bool action);
virtual int getWidth();
virtual int getHeight();
virtual double getFPS();
virtual int getMaxFPS();
protected:
    int width, height;
    double fps;
    int maxFPS = 60;
    bool actionlimitFPS = false;
    bool actionVSync = true;
    std::function<void(double, double)> mousemove_callback;
    std::function<void(double, double, int)> mouseClickedDownCallback;
    std::function<void(double, double, int)> mouseClickedUpCallback;
    std::function<void(double, double, double, double)> mouseScrollCallBack;
    std::function<void(int key, int scancode, int action, int mods, const char* name)> keyPressedCallBack;
    std::function<void(int key, int scancode, int action, int mods, const char* name)> keyReleasedCallBack;
    std::function<void(std::string ch)> characterCallback;
};
#endif
