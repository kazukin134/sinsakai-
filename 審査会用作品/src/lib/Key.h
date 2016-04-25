#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <set>


void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void UpdateKeys();

bool IsPressKey(int key);

bool IsPushKey(int key);

bool IsPullKey(int key);