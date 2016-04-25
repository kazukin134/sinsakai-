#pragma once
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Color.h"
#include <string.h>

class Texture
{
private:
	
	GLuint texture_id;
	int get_texture_width;
	int get_texture_height;

public:
	Texture(const std::string  file, int texture_width, int texture_height);
	
	~Texture();

	int Width() const{ return get_texture_width; };
	int Height() const{ return get_texture_height; };

	void bind() const
	{
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

	void unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}


	void  setupTexture(const std::string  file, int texture_width, int texture_height);

	void DrawTextureBox(float x, float y, float width, float height, float texture_x, float texture_y, float texture_width, float texture_height,
		Color &color);

	void DrawTextureBox(float x, float y, float width, float height, float texture_x, float texture_y, float texture_width, float texture_height,
		Color &color, float angle);

};