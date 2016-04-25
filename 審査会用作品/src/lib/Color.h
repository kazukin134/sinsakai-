#pragma once

#include <GLFW/glfw3.h>
//#include <cstdlib>

class Color
{
public:
	Color(float red, float green, float  blue,float Alpha) {
		glColor4f(red, green, blue, Alpha);
	};

};