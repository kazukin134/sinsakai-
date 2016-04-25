#pragma once
#include "Object.h"
#include "lib\Texture.h"
#include "lib\DrawBox.h"

class CDistance :public Object
{
	Texture goal;
	Texture playerdistance;
	Texture walldistance;
public:
	CDistance();
	~CDistance(){};

	void Draw();
	void Update();
	void Move();

private:

};