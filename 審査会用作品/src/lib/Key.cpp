#include "Key.h"

std::set<int> key_press;
std::set<int> key_push;
std::set<int> key_pull;

//キーの更新(押されたキーを確認する)
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

// キーの更新(入力を一旦クリア) 
void UpdateKeys()
{
	key_push.clear();
	key_pull.clear();
}

//キーを押し続ける時
bool IsPressKey(int key)
{
	return key_press.count(key);
}

//キーを押した時
bool IsPushKey(int key)
{
	return key_push.count(key);
}

//キーを離した時
bool IsPullKey(int key)
{
	return key_pull.count(key);
}