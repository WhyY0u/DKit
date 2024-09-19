#pragma once
#ifndef WindowManager
#define WINDOWMANAGER_H
namespace WindowManager {
    extern int width, height;
	void setScreenSize(int w, int h);
	int getScreenWidth();
	int getScreenHeight();
}
#endif