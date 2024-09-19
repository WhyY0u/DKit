#include "DirectX.h"

DirectX::DirectX() {

}

DirectX::~DirectX() {
    RenderAPI::~RenderAPI();
}

void DirectX::init(){
    RenderAPI::init();
}

void DirectX::createWindow(const std::string &name, const int &width, const int &height){

}

void DirectX::destroyWindow(){

}

void DirectX::mainLoop(std::function<void()> callback) {

}

void DirectX::setScreenFrames(bool frames) {

}

void DirectX::setWindowsIcon(std::string path) {

}

void DirectX::setCallBackMouseMove(std::function<void(double, double)> callback) {
    RenderAPI::setCallBackMouseMove(callback);
}

void DirectX::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedUp(callback);
}

void DirectX::setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedDown(callback);
}

void DirectX::setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) {
     RenderAPI::setCallBackMouseScroll(callback);
}

void DirectX::setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
     RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void DirectX::setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
    RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void DirectX::setCallBackCharacter(std::function<void(const std::string ch)> ch) {
    RenderAPI::setCallBackCharacter(ch);
}

void DirectX::setBackgroundColor(Color color) {

}


void DirectX::setMaxFPS(int max) {
    RenderAPI::setMaxFPS(max);
}

void DirectX::setVSync(bool action) {
    RenderAPI::setVSync(action);
}

void DirectX::enableLimitFPS(bool action) {
     RenderAPI::enableLimitFPS(action);
}

int DirectX::getWidth()
{
    return RenderAPI::getWidth();
}

int DirectX::getHeight()
{
    return RenderAPI::getHeight();
}

double DirectX::getFPS()
{
    return RenderAPI::getFPS();
}

int DirectX::getMaxFPS()
{
    return RenderAPI::getMaxFPS();
}
