#pragma once
#include <GLFW/glfw3.h>
#include <cstdlib>

class Input
{
	bool pullcheck;

public:

	Input();
	~Input(){};

	bool PullMouseButton(GLFWwindow* window, int button);
	bool PressMouseButton(GLFWwindow* window, int button);
	bool PushMouseButton(GLFWwindow* window, int button);
	
};