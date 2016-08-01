#include "Texture.h"

//�w�b�^�[�ł��Ƒ��d��`�ɂȂ�̂Œ���!
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//�R���X�g���N�^�ŉ摜�̓ǂݍ���
//������(�t�@�C�����̃p�X�A�摜�̃s�N�Z���̉����A�摜�̃s�N�Z���̏c���A)

Texture::Texture(const std::string&  file,const int texture_width,const int texture_height)
{
	glGenTextures(1, &texture_id);
	setupTexture(file, texture_width, texture_height);
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id);
}

//�摜�̓ǂݍ���
//������(�t�@�C�����̃p�X�A�摜�̃s�N�Z���̉����A�摜�̃s�N�Z���̏c���A)
void Texture::setupTexture(const std::string&  file, int texture_width, int texture_height)
{
	get_texture_width = texture_width;
	get_texture_height = texture_height;

	unsigned char* pixels;
	int bpp;

	// �t�@�C����ǂݍ��݁A�摜�f�[�^�����o��
	pixels = stbi_load(file.c_str(), &  texture_width, &texture_height, &bpp, 4);


	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexImage2D(GL_TEXTURE_2D, 0,
		GL_RGBA, texture_width, texture_height,
		0, GL_RGBA, GL_UNSIGNED_BYTE,
		&pixels[0]);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_T, GL_REPEAT);

	// ��������̉摜�f�[�^��j��
	stbi_image_free(pixels);

	// �e�N�X�`���̍S��������
	glBindTexture(GL_TEXTURE_2D, 0);

}

//�摜�̕\���֐�
//������(��ʕ\���̍��W���A��ʕ\���̍��W���A��ʕ\���̉����A��ʕ\���̏c���A
//�摜�̐؂���J�n�̍��W���A�摜�̐؂���J�n�̍��W���A�摜�̐؂���̉����A�摜�̐؂���̏c���A�F(r,g,b,alpha)) 
void Texture::DrawTextureBox(const float x, const float y,const float width, const float height,
	const float texture_x, const float texture_y,const float texture_width,const float texture_height,
	Color &color)
{

	const float end_x = x + width;
	const float end_y = y + height;

	const GLfloat vtx[] =
	{
		x, y,
		end_x, y,
		end_x, end_y,
		x, end_y,
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);

	const GLfloat texture_uv[] =
	{
		texture_x / get_texture_width, (texture_y + texture_height) / get_texture_height,
		(texture_x + texture_width) / get_texture_width, (texture_y + texture_height) / get_texture_height,
		(texture_x + texture_width) / get_texture_width, texture_y / get_texture_height,
		texture_x / get_texture_width, texture_y / get_texture_height,

	};


	glTexCoordPointer(2, GL_FLOAT, 0, texture_uv);

	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	bind();



	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glDisable(GL_TEXTURE_2D);
	unbind();
	glDisable(GL_BLEND);
}

//�摜�̕\��(��]�@�\�t��)
//������(��ʕ\���̍��W���A��ʕ\���̍��W���A��ʕ\���̉����A��ʕ\���̏c���A
//�摜�̐؂���J�n�̍��W���A�摜�̐؂���J�n�̍��W���A�摜�̐؂���̉����A�摜�̐؂���̏c���A�F(r,g,b,alpha)�A
//��]�p�x(���W�A��)�A(���A�c)�̊g��k�����A��`�̌��_�ʒu) 
void Texture::DrawTextureBox(const float x,const float y,const float width,const float height,
	const float texture_x,const float texture_y,const float texture_width,const float texture_height,
	Color &color,const float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin)
{

	//// ��]�A�g��k���̍s��𐶐�
	auto matrix = transformMatrix2D(angle,
		Eigen::Vector3f(x, y, 0.0f),
		Eigen::Vector3f(scaling.x(), scaling.y(), 1.0f));

	//// �s���OpenGL�ɐݒ�
	glPushMatrix();
	glMultMatrixf(matrix.data());

	DrawTextureBox(-origin.x(), -origin.y(), width, height,
		texture_x, texture_y, texture_width, texture_height,
		color);

	// �s������ɖ߂�
	glPopMatrix();

}