#pragma once
#include <GLFW/glfw3.h>

//�J���[��ݒ肷��N���X
//������(�ԁA�΁A�A�A���t�@�l)���ꂼ��0�`1�܂łł��B
class Color
{
public:
	Color(float red, float green, float  blue, float Alpha) {
		glColor4f(red, green, blue, Alpha);
	};
};
