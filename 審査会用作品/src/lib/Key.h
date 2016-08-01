#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <set>


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

// �L�[�̍X�V
void UpdateKeys();
//�L�[�����������鎞
bool IsPressKey(int key);
//�L�[����������
bool IsPushKey(int key);
//�L�[�𗣂�����
bool IsPullKey(int key);