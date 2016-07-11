#include "Clear.h"

CClear::CClear():
drawclear("res/png/door/door0405_or2.png",256,256),
logo("res/png/clearlogo.png",1024,512),
clearbgm("res/wav/tw036.wav")
{
	selected_clear = 0;
}

CClear::~CClear(){}

void CClear::Update()
{
	if (!clearbgm.IsPlaying())
	{
		clearbgm.Gain(0.5f);
		clearbgm.Looping(true);
		clearbgm.Play();
	}
	if (IsPushKey(GLFW_KEY_ENTER))
	{
		selected_clear = 1;
		clearbgm.Looping(false);
		clearbgm.Stop();
	}
}

void CClear::Draw()
{
	drawclear.DrawTextureBox(-320, -240, 640, 480, 0, 0, 170, 222, Color(1, 1, 1,1));
	 logo.DrawTextureBox(-150, 0, 300, 80, 3, 83, 628, 78,Color(1, 1, 1,1));
	//drawFillBox(0, 0, 50, 50, Color(0.5, 0.5, 1));
}