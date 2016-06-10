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


class Texture
{
private:
	
	GLuint texture_id;
	int get_texture_width;
	int get_texture_height;
	//typedef Eigen::Quaternion<GLfloat> Quatf;
	//typedef Eigen::Transform<GLfloat,0,0> a;
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
		Color &color, float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin);

};


//typedef Eigen::Quaternion<GLfloat> Quatf;
//typedef Eigen::Translation<float, 3> Translation;
//typedef Eigen::Transform< GLfloat, 3, Eigen::Affine> Affinef;
//
//// FIXME:�R���X�g���N�^��x,y,z�S�ēn���Ȃ��Ə����l������`�ɂȂ�
//typedef Eigen::DiagonalMatrix<GLfloat, 3> Scaling;

//// ��]�A�X�P�[�����O�A���s�ړ�����ϊ��s��𐶐�(2D����)
//// rotate    ��]��(���W�A��)
//// transtate ���s�ړ���
//// scaling   �X�P�[�����O
//Affinef transformMatrix2D(const float rotate_rad, const Eigen::Vector3f& transtate, const Eigen::Vector3f& scaling) {
//	Affinef matrix;
//
//	Translation t(transtate);
//	Scaling s(scaling);
//	Quatf r(Eigen::AngleAxisf(rotate_rad, Eigen::Vector3f::UnitZ()));
//
//	matrix = t * r * s;
//
//	return matrix;
//}