#include "Clear.h"

CClear::CClear():
drawclear("res/raw/door/door0405_or2.raw",256,256),
logo("res/raw/clearlogo.raw",1024,512),
clearbgm("res/wav/tw036.wav")
{
	selected_clear = 0;
}


CClear::~CClear()
{
}

void CClear::Update()
{
	//if (!clearbgm.isPlaying())
	//{
	//	clearbgm.gain(0.05f);
	//	clearbgm.looping(true);
	//	clearbgm.play();
	//}
	if (IsPushKey(GLFW_KEY_ENTER))
	{
		selected_clear = 1;
	//	clearbgm.looping(false);
	//	clearbgm.stop();
	}
}

void CClear::Draw()
{
	
	drawclear.DrawTextureBox(-320, -240, 620, 480, 0, 0, 170, 222, Color(1, 1, 1,1));
	 logo.DrawTextureBox(-150, 0, 300, 80, 3, 83, 628, 78,Color(1, 1, 1,1));
	//drawFillBox(0, 0, 50, 50, Color(0.5, 0.5, 1));

}