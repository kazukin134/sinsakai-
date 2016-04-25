#pragma once
#include "Object.h"
#include "lib\Texture.h"
#include "lib\Key.h"
#include "lib\DrawBox.h"

class CTitle : public Object
{
	Texture title01;
	Texture titlelogo;
	Texture start;
	Texture rule;
	Texture end;
	//Media titlebgm;

public:
	CTitle();
	~CTitle();

	void Update();
	void Draw();


	int title;
	float selected_game;
	float selected_rule;
	float selected_end;
};