#include <iostream>
#include "Dkit.h"
void Render();

int main() {
    startDKIT(RenderAPIType::OpenGL);
    init();
    createWindow("Iniy By " + getRenderAPITypeString(getRenderAPIType()), 800, 600);
    enableLimitFPS(false);
    setVSync(false);
    mainLoop(Render);
    return 0;
}

void Render() {
    std::cout << getFPS() << std::endl;
}

