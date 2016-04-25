#pragma once
#include "lib\Texture.h"

class StartCount
{
	Texture number;
	Texture startlogo;

	int count;
	int time;
public:
	StartCount();
	~StartCount(){};

	int GetTime(){ return time; }

	void Draw();
	void Update();

};