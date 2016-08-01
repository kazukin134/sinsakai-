#pragma once

#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <windows.h>


class WindowSize
{
	//windowサイズ
	int window_width = 640;
	int window_height = 480;

public:

	//windowのサイズを取れるようにした
	int GetWindowGetWidth()
	{
		return window_width;
	}

	int GetWindowGetHeight()
	{
		return window_height;
	}

	//windowのサイズを変更できるようにした
	void SetWindowWidth(int new_window_width)
	{
		window_width = new_window_width;
	}

	void SetWindowHeight(int new_window_height)
	{
		window_height = new_window_height;
	}
};