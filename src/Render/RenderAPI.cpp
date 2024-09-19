#include "RenderAPI.h"

void RenderAPI::init() {

}

void RenderAPI::createWindow(const std::string& name, const int& width, const int& height){

}

void RenderAPI::destroyWindow() {

}

void RenderAPI::mainLoop(std::function<void()> callback) {

}

void RenderAPI::setScreenFrames(bool frames) {

}

void RenderAPI::setWindowsIcon(const std::string &path) {
   
}

void RenderAPI::setCallBackMouseMove(std::function<void(double, double)> callback) {
  mousemove_callback = callback;
}

void RenderAPI::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    mouseClickedUpCallback = callback;
}

void RenderAPI::setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) {
    mouseClickedDownCallback = callback;
}

void RenderAPI::setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) {
     mouseScrollCallBack = callback;
}

void RenderAPI::setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char *name)> callback) {
       keyPressedCallBack = callback;
}

void RenderAPI::setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char *name)> callback) {
    keyReleasedCallBack = callback;
}

void RenderAPI::setCallBackCharacter(std::function<void(const std::string ch)> callback) {
        characterCallback = callback;
}

void RenderAPI::setBackgroundColor(Color color) {
    
}

void RenderAPI::setMaxFPS(int max) {
     maxFPS = max;
}

void RenderAPI::setVSync(bool action) {
    actionVSync = action;
}

void RenderAPI::enableLimitFPS(bool action) {
    this->actionlimitFPS = action;
}

int RenderAPI::getWidth()
{
    return width;
}

int RenderAPI::getHeight()
{
    return height;
}
double RenderAPI::getFPS()
{
    return fps;
}

int RenderAPI::getMaxFPS()
{
    return maxFPS;
}
