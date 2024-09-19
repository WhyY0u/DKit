#include "Vulkan.h"

Vulkan::Vulkan() {

}

Vulkan::~Vulkan() {
    RenderAPI::~RenderAPI();
}

void Vulkan::init(){
    RenderAPI::init();
}

void Vulkan::createWindow(const std::string &name, const int &width, const int &height){

}

void Vulkan::destroyWindow(){

}

void Vulkan::mainLoop(std::function<void()> callback) {

}

void Vulkan::setScreenFrames(bool frames) {

}

void Vulkan::setWindowsIcon(std::string path) {

}

void Vulkan::setCallBackMouseMove(std::function<void(double, double)> callback) {
    RenderAPI::setCallBackMouseMove(callback);
}

void Vulkan::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedUp(callback);
}

void Vulkan::setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedDown(callback);
}

void Vulkan::setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) {
     RenderAPI::setCallBackMouseScroll(callback);
}

void Vulkan::setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
     RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void Vulkan::setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
    RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void Vulkan::setCallBackCharacter(std::function<void(const std::string ch)> ch) {
    RenderAPI::setCallBackCharacter(ch);
}

void Vulkan::setBackgroundColor(Color color) {

}


void Vulkan::setMaxFPS(int max) {
    RenderAPI::setMaxFPS(max);
}

void Vulkan::setVSync(bool action) {
    RenderAPI::setVSync(action);
}

void Vulkan::enableLimitFPS(bool action) {
     RenderAPI::enableLimitFPS(action);
}

int Vulkan::getWidth()
{
    return RenderAPI::getWidth();
}

int Vulkan::getHeight()
{
    return RenderAPI::getHeight();
}

double Vulkan::getFPS()
{
    return RenderAPI::getFPS();
}

int Vulkan::getMaxFPS()
{
    return RenderAPI::getMaxFPS();
}
