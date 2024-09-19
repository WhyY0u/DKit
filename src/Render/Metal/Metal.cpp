#include "Metal.h"

Metal::Metal() {

}

Metal::~Metal() {
    RenderAPI::~RenderAPI();
}

void Metal::init(){
    RenderAPI::init();
}

void Metal::createWindow(const std::string &name, const int &width, const int &height){

}

void Metal::destroyWindow(){

}

void Metal::mainLoop(std::function<void()> callback) {

}

void Metal::setScreenFrames(bool frames) {

}

void Metal::setWindowsIcon(std::string path) {

}

void Metal::setCallBackMouseMove(std::function<void(double, double)> callback) {
    RenderAPI::setCallBackMouseMove(callback);
}

void Metal::setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedUp(callback);
}

void Metal::setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) {
    RenderAPI::setCallBackMouseClickedDown(callback);
}

void Metal::setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) {
     RenderAPI::setCallBackMouseScroll(callback);
}

void Metal::setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
     RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void Metal::setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char *name)> keyTypedCallBack) {
    RenderAPI::setCallBackKeyReleased(keyTypedCallBack);
}

void Metal::setCallBackCharacter(std::function<void(const std::string ch)> ch) {
    RenderAPI::setCallBackCharacter(ch);
}

void Metal::setBackgroundColor(Color color) {

}


void Metal::setMaxFPS(int max) {
    RenderAPI::setMaxFPS(max);
}

void Metal::setVSync(bool action) {
    RenderAPI::setVSync(action);
}

void Metal::enableLimitFPS(bool action) {
     RenderAPI::enableLimitFPS(action);
}

int Metal::getWidth()
{
    return RenderAPI::getWidth();
}

int Metal::getHeight()
{
    return RenderAPI::getHeight();
}

double Metal::getFPS()
{
    return RenderAPI::getFPS();
}

int Metal::getMaxFPS()
{
    return RenderAPI::getMaxFPS();
}
