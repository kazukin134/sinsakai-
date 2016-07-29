#pragma once

#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <windows.h>


class WindowSize
{
	int window_width = 640;
	int window_height = 480;

public:

	int GetWindowWidth()
	{
		return window_width;
	}

	int GetWindowHeight()
	{
		return window_height;
	}

	void SetWindowWidth(int new_window_width)
	{
		window_width = new_window_width;
	}

	void SetWindowHeight(int new_window_height)
	{
		window_height = new_window_height;
	}
};