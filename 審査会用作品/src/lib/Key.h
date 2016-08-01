#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <set>


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

// キーの更新
void UpdateKeys();
//キーを押し続ける時
bool IsPressKey(int key);
//キーを押した時
bool IsPushKey(int key);
//キーを離した時
bool IsPullKey(int key);