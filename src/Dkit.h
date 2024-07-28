#ifndef DKIT_H
#define DKIT_H

#include <string>
#include <functional>
#include "Utils/ColorUtils/ColorUtils.h"
#include <iostream>
#include "Managers/ElementManager/ElementManager.h"

enum class RenderAPI {
    Vulkan,
    OpenGL,
    DirectX,
    Metal,
};
RenderAPI renderApi = RenderAPI::OpenGL;
#ifdef DKITOpenGL
#include "Render/OpenGL/OpenGL.h"
OpenGL opengl = OpenGL();
#endif

#ifdef DKITVulkan
#include "Render/Vulkan/Vulkan.h"
#endif

#ifdef DKITDirectX
#include "Render/DirectX/DirectX.h"
#endif

#ifdef DKITDirectX
#include "Render/DirectX/DirectX.h"
#endif

#ifdef DKITMetal
#include "Render/DirectX/DirectX.h"
#endif

void startDKIT() {
    #ifdef DKITOpenGL
    renderApi = RenderAPI::OpenGL;
    std::cout << "Init OpenGL" << std::endl;
    #endif

    #ifdef DKITVulkan
    renderApi = RenderAPI::Vulkan;
    std::cout << "Init Vulkan" << std::endl;
    #endif

    #ifdef DKITDirectX
    renderApi = RenderAPI::DirectX;
    std::cout << "Init DirectX" << std::endl;
    #endif

    #ifdef DKITMetal
    renderApi = RenderAPI::Metal;
    std::cout << "Init Metal" << std::endl;
    #endif
}
void init() {
#ifdef DKITOpenGL
    opengl.init();
#endif
}
void createWindow(const std::string& name, int width, int height) {
#ifdef DKITOpenGL
    opengl.createWindow(name, width, height);
#endif
}
void destroyWindow() {
#ifdef DKITOpenGL
    opengl.destroyWindow();
#endif
}
void mainLoop(std::function<void()> callback) {
#ifdef DKITOpenGL
    opengl.mainLoop(callback);
#endif
}
void setScreenFrames(bool frames) {
#ifdef DKITOpenGL
    opengl.setScreenFrames(frames);
#endif
}
void setWindowsIcon(const std::string& path) {
#ifdef DKITOpenGL
    opengl.setWindowsIcon(path);
#endif
}
void setCallbackMouseMove(std::function<void(double, double)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackMouseMove(callback);
#endif
}
void setCallbackMouseClickedUp(std::function<void(double, double, int)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackMouseClickedUp(callback);
#endif
}
void setCallbackMouseClickedDown(std::function<void(double, double, int)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackMouseClickedDown(callback);
#endif
}
void setCallbackMouseScroll(std::function<void(double, double, double, double)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackMouseScroll(callback);
#endif
}
void setCallbackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackKeyPressed(callback);
#endif
}
void setCallbackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackKeyReleased(callback);
#endif
}
void setCallbackCharacter(std::function<void(const std::string& ch)> callback) {
#ifdef DKITOpenGL
    opengl.setCallBackCharacter(callback);
#endif
}
void setBackgroundColor(Color color) {
#ifdef DKITOpenGL
    opengl.setBackgroundColor(color);
#endif
}
void setMaxFPS(int max) {
#ifdef DKITOpenGL
    opengl.setMaxFPS(max);
#endif
}
void setVSync(bool action) {
#ifdef DKITOpenGL
    opengl.setVSync(action);
#endif
}
void enableLimitFPS(bool action) {
#ifdef DKITOpenGL
    opengl.enableLimitFPS(action);
#endif
}
int getWidth() {
#ifdef DKITOpenGL
    return opengl.getWidth();
#endif
}
int getHeight() {
#ifdef DKITOpenGL
    return opengl.getHeight();
#endif
}
double getFPS() {
#ifdef DKITOpenGL
    return opengl.getFPS();
#endif
}
int getMaxFPS() {
#ifdef DKITOpenGL
    return opengl.getMaxFPS();
#endif
}
RenderAPI getRenderAPI() {
    return renderApi;
}
std::string getRenderAPIString(RenderAPI api) {
    switch (api) {
    case RenderAPI::Vulkan: return "Vulkan";
    case RenderAPI::OpenGL: return "OpenGL";
    case RenderAPI::DirectX: return "DirectX";
    case RenderAPI::Metal: return "Metal";
    default: return "Unknown";
    }
}

#endif 
