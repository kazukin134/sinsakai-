#include "Key.h"

std::set<int> key_press;
std::set<int> key_push;
std::set<int> key_pull;


void KeyCallback(GLFWwindow* window, int key,
	int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
		key_press.insert(key);
		key_push.insert(key);
		break;

	case GLFW_RELEASE:
		key_press.erase(key);
		key_pull.insert(key);
		break;
	}
}

void UpdateKeys()
{
	key_push.clear();
	key_pull.clear();
}

bool IsPressKey(int key)
{
	return key_press.count(key);
}

bool IsPushKey(int key)
{
	return key_push.count(key);
}

bool IsPullKey(int key)
{
	return key_pull.count(key);
}
