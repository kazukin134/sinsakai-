#pragma once
#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <string>
#include <streambuf>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>


#include "lib/Input.h"
#include "lib/DrawBox.h"
#include "lib/Color.h"
#include "Scene.h"
#include "lib/DrawBox.h"
#include "lib/Audio.h"
#include "lib/WindowSize.h"


class DbgStreambuf : public std::streambuf {
	std::vector<TCHAR> str_;
	// ªOutputDebugString()‚ªchar‚Å‚Í‚È‚­TCHAR‚ð—v‹‚·‚é

public:
	int_type overflow(int_type c = EOF) {
		str_.push_back(c);
		return c;
	}

	int sync() {
		str_.push_back('\0');

		OutputDebugString(&str_[0]);
		str_.clear();
		return 0;
	}
};


void ChangeWindowSize3D(GLFWwindow * window, const int width, const int height)
{
	glViewport(0, 0, width, height);
	WindowSize windowsize;
	windowsize.SetWindowWidth(width);
	windowsize.SetWindowHeight(height);

}

int main()
{
	DbgStreambuf dbg_stream;
	//std::streambuf* stream;
	GLFWwindow* window;
	WindowSize windowsize;

	int window_width = windowsize.GetWindowWidth();
	int window_height = windowsize.GetWindowHeight();

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(window_width, window_height, "sinsakai", NULL, NULL);

	//window‚ªì‚ê‚È‚©‚Á‚½‚çI—¹
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(window, ChangeWindowSize3D);

	glfwMakeContextCurrent(window);

	Audio audio;
	CScene scene;

	glOrtho(-window_width / 2, window_width / 2, -window_height / 2, window_height / 2, -1.0f, 1.0f);

	glfwSetKeyCallback(window, KeyCallback);

	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);

		scene.Main();

		UpdateKeys();

		glfwSwapBuffers(window);

		glfwPollEvents();

		if (CScene::Title->selected_end == 1)
		{
			break;
		}
	}
	glfwTerminate();
	return 0;
}