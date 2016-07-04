#include "Texture.h"
#include "png.h"

Texture::Texture(const std::string  file, int texture_width, int texture_height)
{
	glGenTextures(1, &texture_id);
	setupTexture(file, texture_width, texture_height);
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id);
}

void Texture::setupTexture(const std::string  file, int texture_width, int texture_height)
{
	get_texture_width = texture_width;
	get_texture_height = texture_height;

	std::ifstream fstr(file, std::ios::binary);
	if (!fstr)return;

	const size_t file_size
		= static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
	fstr.seekg(0, fstr.beg);

	std::vector<char> texture_buffer(file_size);

	fstr.read(&texture_buffer[0], file_size);

	//unsigned char* pixels;

	// ファイルを読み込み、画像データを取り出す
//	pixels = stbi_load(file.c_str(), &texture_width, &texture_height, &bpp, 4);


	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexImage2D(GL_TEXTURE_2D, 0,
		GL_RGBA, texture_width, texture_height,
		0, GL_RGBA, GL_UNSIGNED_BYTE,
		&texture_buffer[0]);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_WRAP_T, GL_REPEAT);

}

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

void Texture::DrawTextureBox(const float x,const float y,const float width,const float height,
	const float texture_x,const float texture_y,const float texture_width,const float texture_height,
	Color &color,const float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin)
{

	//// 回転、拡大縮小の行列を生成
	auto matrix = transformMatrix2D(angle,
		Eigen::Vector3f(x, y, 0.0f),
		Eigen::Vector3f(scaling.x(), scaling.y(), 1.0f));

	//// 行列をOpenGLに設定
	glPushMatrix();
	glMultMatrixf(matrix.data());

	DrawTextureBox(-origin.x(), -origin.y(), width, height,
		texture_x, texture_y, texture_width, texture_height,
		color);

	// 行列を元に戻す
	glPopMatrix();

}