#ifndef DIRECTX_H
#define DIRECTX_H
#include "RenderAPI.h"
class DirectX : public RenderAPI {
public:
    DirectX();
    ~DirectX();

    void init() override;
    void createWindow(const std::string& name, const int& width, const int& height) override;
    void destroyWindow();
    void mainLoop(std::function<void()> callback) override;
    void setScreenFrames(bool frames) override;
    void setWindowsIcon(std::string path);
    void setCallBackMouseMove(std::function<void(double, double)> callback) override;
    void setCallBackMouseClickedUp(std::function<void(double, double, int)> callback) override; 
    void setCallBackMouseClickedDown(std::function<void(double, double, int)> callback) override;
    void setCallBackMouseScroll(std::function<void(double, double, double, double)> callback) override;
    void setCallBackKeyPressed(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackKeyReleased(std::function<void(int key, int scancode, int action, int mods, const char* name)> keyTypedCallBack) override;
    void setCallBackCharacter(std::function<void(const std::string ch)> ch) override;
    void setBackgroundColor(Color color) override;
    void setMaxFPS(int max) override;
    void setVSync(bool action) override;
    void enableLimitFPS(bool action) override;
    int getWidth() override;
    int getHeight() override;
    double getFPS() override;
    int getMaxFPS() override;
    

private:
};


#endif