#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#ifdef DKITOpenGL
#include "Render/Square/OpenGL/Square.h"
#endif

void drawSquare(float x, float y, float width, float height, Color color) {
	#ifdef DKITOpenGL
	SquareOpenGL::drawSquare(x, y, width, height, color);
	#endif
}
#endif