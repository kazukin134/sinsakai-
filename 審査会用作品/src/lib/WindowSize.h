#pragma once

#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <windows.h>


class WindowSize
{
	//window�T�C�Y
	int window_width = 640;
	int window_height = 480;

public:

	//window�̃T�C�Y������悤�ɂ���
	int GetWindowGetWidth()
	{
		return window_width;
	}

	int GetWindowGetHeight()
	{
		return window_height;
	}

	//window�̃T�C�Y��ύX�ł���悤�ɂ���
	void SetWindowWidth(int new_window_width)
	{
		window_width = new_window_width;
	}

	void SetWindowHeight(int new_window_height)
	{
		window_height = new_window_height;
	}
};