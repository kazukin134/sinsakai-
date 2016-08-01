#pragma once
#include <GLFW/glfw3.h>
#include <cstdlib>

//マウスの入力のクラス
class Input
{
	bool pullcheck;

public:

	Input();
	~Input(){};

	//ボタン離した時
	bool PullMouseButton(GLFWwindow* window, int button);

	//ボタン押し続けてる時
	bool PressMouseButton(GLFWwindow* window, int button);

	//ボタン押した時
	bool PushMouseButton(GLFWwindow* window, int button);
	
};