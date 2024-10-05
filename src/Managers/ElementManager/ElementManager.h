#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#include "Render/Square/OpenGL/Square.h"

void drawSquare(float x, float y, float width, float height, Color color) {
	SquareOpenGL::drawSquare(x, y, width, height, color);
}

#endif