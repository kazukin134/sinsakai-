#pragma once
#include <GLFW/glfw3.h>
#include <cstdlib>

//�}�E�X�̓��͂̃N���X
class Input
{
	bool pullcheck;

public:

	Input();
	~Input(){};

	//�{�^����������
	bool PullMouseButton(GLFWwindow* window, int button);

	//�{�^�����������Ă鎞
	bool PressMouseButton(GLFWwindow* window, int button);

	//�{�^����������
	bool PushMouseButton(GLFWwindow* window, int button);
	
};