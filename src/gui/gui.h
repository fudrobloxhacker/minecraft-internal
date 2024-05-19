#ifndef GUI_H_
#define GUI_H_

#include <cstdio>

#include <Windows.h>

namespace GUI
{
	bool init(HWND wnd_handle);
	void shutdown();
	void draw();
	bool getIsInit();
	bool getDoDraw();

	void setDoDraw(bool new_value);
}

#endif