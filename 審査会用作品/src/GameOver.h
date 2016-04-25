#pragma once

#include "Object.h"
#include "GameMain.h"
//#include "Player.h"
#include "Scene.h"
#include "lib\Texture.h"
#include "lib\DrawBox.h"
#include "lib\Key.h"

class CGameOver : public  Object
{
	Texture retry_or_title;
	Texture drawover;
	Texture gameoverlogo;

//	Media gameoverbgm;

public:
	CGameOver();
	~CGameOver();

	void Draw();
	void Update();
	void Choice();
	
	
	float selected;
	int choice;

	float  selected_title;
};
	