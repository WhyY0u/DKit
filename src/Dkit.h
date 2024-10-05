#ifndef DKIT_H
#define DKIT_H

#include <memory>
#include <string>
#include <functional>
#include <iostream>

#include "RenderAPI.h"
#include "Managers/ElementManager/ElementManager.h"

#include "OpenGL.h"
#include "Vulkan.h"
#include "DirectX.h"
#include "Metal.h"

enum class RenderAPIType {
    Vulkan,
    OpenGL,
    DirectX,
    Metal,
};
RenderAPIType renderAPIType = RenderAPIType::OpenGL;

RenderAPI* renderAPI;

RenderAPI* createRenderAPI(RenderAPIType type) {
      switch (type) {
     case RenderAPIType::Vulkan:
         return new Vulkan();
     break;

     case RenderAPIType::OpenGL:
         return new OpenGL();
     break;

     case RenderAPIType::DirectX:
         return new DirectX();
     break;

     case RenderAPIType::Metal:
         return new Metal();
     break;

     default:
        return new OpenGL();
     break;
      }
}
 
void startDKIT(RenderAPIType api) {
    renderAPIType = api;
    renderAPI = createRenderAPI(api);
    if(api == RenderAPIType::OpenGL) {
    std::cout << "Init OpenGL" << std::endl;
    }

    if(api == RenderAPIType::Vulkan) {
    std::cout << "Init Vulkan" << std::endl;
    }

    if(api == RenderAPIType::DirectX) {
    std::cout << "Init DirectX" << std::endl;
    }

    if(api == RenderAPIType::Metal) {
    std::cout << "Init Metal" << std::endl;
    }

}
void init() {
    renderAPI->init();
}
void createWindow(const std::string& name, int width, int height) {
    renderAPI->createWindow(name, width, height);
}
void destroyWindow() {
   renderAPI->destroyWindow();
}
void mainLoop(std::function<void()> callback) {
   renderAPI->mainLoop(callback);
}
void setScreenFrames(bool frames) {
    renderAPI->setScreenFrames(frames);
}
void setWindowsIcon(const std::string& path) {
    renderAPI->setWindowsIcon(path);
}
void setCallbackMouseMove(std::function<void(double, double)> callback) {
    renderAPI->setCallBackMouseMove(callback);
}
void setCallbackMouseClickedUp(std::function<void(double, double, int)> callback) {
    renderAPI->setCallBackMouseClickedUp(callback);
}
void setCallbackMouseClickedDown(std::function<void(double, double, int)> callback) {
    renderAPI->setCallBackMouseClickedDown(callback);
}
void setCallbackMouseScroll(std::function<void(double, double, double, double)> callback) {
    renderAPI->setCallBackMouseScroll(callback);
}
void setCallbackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
    renderAPI->setCallBackKeyPressed(callback);
}
void setCallbackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
    renderAPI->setCallBackKeyReleased(callback);
}
void setCallbackCharacter(std::function<void(const std::string& ch)> callback) {
    renderAPI->setCallBackCharacter(callback);
}
void setBackgroundColor(Color color) {
    renderAPI->setBackgroundColor(color);
}
void setMaxFPS(int max) {
    renderAPI->setMaxFPS(max);
}
void setVSync(bool action) {
    renderAPI->setVSync(action);
}
void enableLimitFPS(bool action) {
    renderAPI->enableLimitFPS(action);
}
int getWidth() {
    return renderAPI->getWidth();
}
int getHeight() {
    return renderAPI->getHeight();
}
double getFPS() {
    return renderAPI->getFPS();
}
int getMaxFPS() {
    return renderAPI->getMaxFPS();
}
RenderAPIType getRenderAPIType() {
    return renderAPIType;
}
std::string getRenderAPITypeString(RenderAPIType api) {
    switch (api) {
    case RenderAPIType::Vulkan: return "Vulkan";
    case RenderAPIType::OpenGL: return "OpenGL";
    case RenderAPIType::DirectX: return "DirectX";
    case RenderAPIType::Metal: return "Metal";
    default: return "Unknown";
    }
}

#endif
