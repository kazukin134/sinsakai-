#include "Rule.h"

CRule::CRule() :rule01("res/png/rule01.png",1024,512)
{
	rule_draw = 0;
}

CRule::~CRule(){}

void CRule::Update()
{
	if (IsPushKey(GLFW_KEY_ENTER))
	{
		rule_draw++;
	}

	if (rule_draw >= 3)
	{
		rule_draw = 0;
	}
}

void CRule::Draw()
{
	if (rule_draw == 0)
	{
		rule01.DrawTextureBox(-320, -240, 650, 500, 0, 0, 1024, 505, Color(1, 1, 1, 1));
	}
}