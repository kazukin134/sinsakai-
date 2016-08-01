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
	//コンストラクタで画像の読み込み
	//引数は(ファイル名のパス、画像のピクセルの横幅、画像のピクセルの縦幅、)
	Texture(const std::string& file,const int texture_width,const int texture_height);

	~Texture();

	//画像のピクセルの横幅が取れる
	int GetWidth() const{ return get_texture_width; };
	//画像のピクセルの縦幅が取れる
	int GetHeight() const{ return get_texture_height; };

	//テクスチャのバインドする
	void bind() const
	{
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

	//テクスチャのバインドを解除する
	void unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	//画像の読み込み
	//引数は(ファイル名のパス、画像のピクセルの横幅、画像のピクセルの縦幅、)
	void  setupTexture(const std::string&  file,  int texture_width,  int texture_height);

	//画像の表示関数
	//引数は(画面表示の座標ｘ、画面表示の座標ｙ、画面表示の横幅、画面表示の縦幅、
	//画像の切り取り開始の座標ｘ、画像の切り取り開始の座標ｙ、画像の切り取りの横幅、画像の切り取りの縦幅、色(r,g,b,alpha)) 
	void DrawTextureBox(const float x, const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color);

	//画像の表示(回転機能付き)
	//引数は(画面表示の座標ｘ、画面表示の座標ｙ、画面表示の横幅、画面表示の縦幅、
	//画像の切り取り開始の座標ｘ、画像の切り取り開始の座標ｙ、画像の切り取りの横幅、画像の切り取りの縦幅、色(r,g,b,alpha)、
	//回転角度(ラジアン)、(横、縦)の拡大縮小率、矩形の原点位置) 
	void DrawTextureBox(const float x,const float y,const float width,const float height,const float texture_x,const float texture_y,const float texture_width,const float texture_height,
		 Color &color,const float angle, const Eigen::Vector2f& scaling, const Eigen::Vector2f& origin);

};