#pragma once
#include <GLFW/glfw3.h>

//カラーを設定するクラス
//引数は(赤、緑、青、アルファ値)それぞれ0～1までです。
class Color
{
public:
	Color(float red, float green, float  blue, float Alpha) {
		glColor4f(red, green, blue, Alpha);
	};
};
