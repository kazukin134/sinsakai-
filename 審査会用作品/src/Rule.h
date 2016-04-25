#pragma once
#include "lib/Texture.h"
#include "lib/Key.h"

class CRule
{
	Texture rule01;
public:
	CRule();
	~CRule();

	void Update();
	void Draw();

	float rule_draw;
};

