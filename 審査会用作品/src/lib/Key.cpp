#include "Key.h"

std::set<int> key_press;
std::set<int> key_push;
std::set<int> key_pull;

//�L�[�̍X�V(�����ꂽ�L�[���m�F����)
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

// �L�[�̍X�V(���͂���U�N���A) 
void UpdateKeys()
{
	key_push.clear();
	key_pull.clear();
}

//�L�[�����������鎞
bool IsPressKey(int key)
{
	return key_press.count(key);
}

//�L�[����������
bool IsPushKey(int key)
{
	return key_push.count(key);
}

//�L�[�𗣂�����
bool IsPullKey(int key)
{
	return key_pull.count(key);
}