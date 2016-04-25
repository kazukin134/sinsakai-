#include "Input.h"

enum Mouse {
	LEFT = GLFW_MOUSE_BUTTON_LEFT,
	RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
};


Input::Input()
{
	pullcheck = false;
}

bool Input::PullMouseButton(GLFWwindow* window, int button)
{
	bool pullmouse = false;
	if (glfwGetMouseButton(window, button) == 1)
	{
		pullmouse = true;
		pullcheck = pullmouse;
	}
	else
	{
		pullmouse = false;
	}

	if (pullmouse == false && pullcheck == true)
	{
		pullcheck = false;
		return true;
	}

	return false;
}

bool Input::PressMouseButton(GLFWwindow* window, int button)
{
	if (glfwGetMouseButton(window, button) == 0)return false;
	return true;
}

bool Input::PushMouseButton(GLFWwindow* window, int button)
{
	bool pullmouse = false;
	if (glfwGetMouseButton(window, button) == 1)
	{
		pullmouse = true;
	}
	else
	{
		pullmouse = false;
	}

	if (pullmouse == true && pullcheck == false)
	{
		pullcheck = true;
		return true;
	}
	else
		if (pullmouse == false && pullcheck == true)
		{
			pullcheck = false;
		}
	return false;
}
