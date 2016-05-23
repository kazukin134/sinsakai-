#pragma once
#include "lib\Texture.h"
#include "lib\Key.h"
#include "lib\Audio.h"

class CClear
{
	Texture drawclear;
	Texture logo;
	Media clearbgm;
public:
	CClear();
	~CClear();

	void Update();
	void Draw();

	float selected_clear;

};