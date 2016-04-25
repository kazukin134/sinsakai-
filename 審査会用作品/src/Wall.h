#pragma once
#include "Object.h"
#include "Collision.h"

class CWall :public Object
{

	//Texture wall;

public:
	CWall();
	~CWall();

	void Move();
	void Collision();
	void Draw();
	void Update();

	float screenspeed; //実際の移動スピード
	

};