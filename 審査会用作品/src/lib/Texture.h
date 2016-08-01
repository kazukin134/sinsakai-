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

public:
	//�R���X�g���N�^�ŉ摜�̓ǂݍ���
	//������(�t�@�C�����̃p�X�A�摜�̃s�N�Z���̉����A�摜�̃s�N�Z���̏c���A)
	Texture(const std::string& file,const int texture_width,const int texture_height);

	~Texture();

	//�摜�̃s�N�Z���̉���������
	int GetWidth() const{ return get_texture_width; };
	//�摜�̃s�N�Z���̏c��������
	int GetHeight() const{ return get_texture_height; };

	//�e�N�X�`���̃o�C���h����
	void bind() const
	{
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

	//�e�N�X�`���̃o�C���h����������
	void unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	//�摜�̓ǂݍ���
	//������(�t�@�C�����̃p�X�A�摜�̃s�N�Z���̉����A�摜�̃s�N�Z���̏c���A)
	void  setupTexture(const std::string&  file,  int texture_width,  int texture_height);

	//�摜�̕\���֐�
	//������(��ʕ\���̍��W���A��ʕ\���̍��W���A��ʕ\���̉����A��ʕ\���̏c���A
	//�摜�̐؂���J�n�̍��W���A�摜�̐؂���J�n�̍��W���A�摜�̐؂���̉����A�摜�̐؂���̏c���A�F(r,g,b,alpha)) 
	void DrawTextureBox(const float x, const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color);

	//�摜�̕\��(��]�@�\�t��)
	//������(��ʕ\���̍��W���A��ʕ\���̍��W���A��ʕ\���̉����A��ʕ\���̏c���A
	//�摜�̐؂���J�n�̍��W���A�摜�̐؂���J�n�̍��W���A�摜�̐؂���̉����A�摜�̐؂���̏c���A�F(r,g,b,alpha)�A
	//��]�p�x(���W�A��)�A(���A�c)�̊g��k�����A��`�̌��_�ʒu) 
	void DrawTextureBox(const float x,const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color,const float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin);

};