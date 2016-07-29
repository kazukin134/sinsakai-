#pragma once

#include <GLFW/glfw3.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Color.h"
#include <string.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "Matrix.h"


//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

class Texture
{
private:

	GLuint texture_id;
	int get_texture_width;
	int get_texture_height;

public:
	Texture(const std::string&  file,const int texture_width,const int texture_height);

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

	void  setupTexture(const std::string&  file,  int texture_width,  int texture_height);

	void DrawTextureBox(const float x, const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color);

	void DrawTextureBox(const float x,const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color,const float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin);

};