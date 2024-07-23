#include "WindowManager.h"
namespace WindowManager {
	int width = 800;
	int height = 600; 
	void setScreenSize(int w, int h) {
		width = w;
		height = h;
	}
	int getScreenWidth() {
		return width;
	}
	int getScreenHeight() {
		return height;
	}
}