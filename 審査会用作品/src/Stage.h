#pragma once
#include "Object.h"
#include "Collision.h"
#include "lib/Texture.h"
#include "lib\DrawBox.h"
#include "lib\Audio.h"
class CStage :public Object
{
	Texture stage;
	Texture floor;
	Texture door;
	Texture drawfall;

	Media standardbgm;
	Media wallbgm;
	float goalposition;

public:
	CStage();
	~CStage();
	
	void Scroll(bool is_scroll, float &scroll_x, float speed);
	void Draw();
	void Update();
	void FallTrap();

	float seflag;
	float fallx;		//落とし穴のx座標

	static const int fall_number  = 5;
	float fall[fall_number];

	float getgoalposition()
	{
		return goalposition;
	};

};

