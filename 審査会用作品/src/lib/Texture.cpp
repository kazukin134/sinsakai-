#include "Texture.h"

Texture::Texture(const std::string  file, int texture_width, int texture_height)
{
	glGenTextures(1, &texture_id);
	setupTexture( file, texture_width,  texture_height);
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

void Texture::DrawTextureBox(float x, float y, float width, float height,
	float texture_x, float texture_y, float texture_width, float texture_height,
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

void Texture::DrawTextureBox(float x, float y, float width, float height,
	float texture_x, float texture_y, float texture_width, float texture_height,
	Color &color, float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin)
{
	//float texture_width_half = texture_width / 2;
	//float texture_height_half = texture_height / 2;


	//// âÒì]ÅAägëÂèkè¨ÇÃçsóÒÇê∂ê¨
	//auto matrix = transformMatrix2D(angle_rad,
	//	Vec3f(start_x, start_y, 0.0f),
	//	Vec3f(scaling.x(), scaling.y(), 1.0f));

	//// çsóÒÇOpenGLÇ…ê›íË
	//glPushMatrix();
	//glMultMatrixf(matrix.data());


	//texture_x = ((texture_width - texture_width_half) * cos(angle)  - (texture_height - texture_height_half) * sin(angle)+(texture_width_half));
	//texture_y = ((texture_width - texture_width_half) * sin(angle) + (texture_height - texture_height_half) * cos(angle) + (texture_height_half));

	//texture_width = ((texture_x - texture_width_half) * cos(-angle) - (texture_y - texture_height_half) * sin(-angle) + (texture_width_half));
	//texture_height = ((texture_x - texture_width_half) * sin(-angle) + (texture_y - texture_height_half) * cos(-angle) +(texture_height_half));

    
	//// âÒì]ÅAägëÂèkè¨ÇÃçsóÒÇê∂ê¨
	auto matrix = transformMatrix2D(angle,
		Eigen::Vector3f(x, y, 0.0f),
		Eigen::Vector3f(scaling.x(), scaling.y(), 1.0f));

	//// çsóÒÇOpenGLÇ…ê›íË
	glPushMatrix();
	glMultMatrixf(matrix.data());
	//Quatf r(Eigen::AngleAxisf(angle, Eigen::Vector3f::UnitZ()));

	DrawTextureBox(-origin.x(), -origin.y(), width, height,
		 texture_x,  texture_y,  texture_width,  texture_height,
		color);
	
		// çsóÒÇå≥Ç…ñﬂÇ∑
	glPopMatrix();

}
