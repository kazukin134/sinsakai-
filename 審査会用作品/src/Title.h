#pragma once
#include "Object.h"
#include "lib\Key.h"
#include "lib\DrawBox.h"
#include "lib\Audio.h"
#include "lib\Texture.h"

class CTitle : public Object
{
	Texture title01;
	Texture titlelogo;
	Texture start;
	Texture rule;
	Texture end;
	Texture menu_background;

	Media titlebgm;
	
	enum SELECTTITLE
	{
		GAME,
		RULE,
		END,
	};

public:
	CTitle();
	~CTitle();

	void Update();
	void Draw();

	int titlecount;
	SELECTTITLE title;
	float selected_game;
	float selected_rule;
	float selected_end;

};