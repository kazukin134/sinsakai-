#pragma once
#include "lib\Texture.h"
#include "lib\Audio.h"
class CDoor
{
	Texture door01;
	Texture door02;
	Texture door03;
	Texture door04;
	Texture door05;
	Media doorse;

public:
	CDoor();
	~CDoor();
	void Draw();
	void Update();
	int doorcount;
	int doordrawcount;
	int doorflag;
	float selected_door;

	
};
