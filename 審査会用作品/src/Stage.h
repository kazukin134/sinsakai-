#pragma once
#include "Object.h"
#include "Collision.h"
#include "lib/Texture.h"
#include "lib\DrawBox.h"

class CStage :public Object
{
	Texture stage;
	Texture floor;
	Texture door;
	Texture drawfall;


	//Media standardbgm;
	//Media wallbgm;

public:
	CStage();
	~CStage();
	
	void Scroll(bool is_scroll, float &scrollX, float speed);
	void Draw();
	void Update();
	void FallTrap();

	float seflag;
	
	float fallx;		//óéÇ∆ÇµåäÇÃxç¿ïW
	float fall[10];

};

