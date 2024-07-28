#include <iostream>
#define DKITOpenGL
#include "Dkit.h"
void Render();
int main() {
    startDKIT();
    init();
    createWindow("Iniy By " + getRenderAPIString(getRenderAPI()), 800, 600);
    setScreenFrames(false);
    enableLimitFPS(false);
    setVSync(false);
    mainLoop(Render);
    return 0;
}

void Render() {
    std::cout << getFPS() << std::endl;
}

