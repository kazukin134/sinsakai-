#include "Door.h"
#include "Stage.h"
#include "Scene.h"

CDoor::CDoor():
door01("res/png/door/door0801.png",256,256) ,
door02("res/png/door/door0202_or2.png",256,256) ,
door03("res/png/door/door0503_or2.png",256,256) ,
door04("res/png/door/door0904_or2.png",256,256) ,
door05("res/png/door/door0405_or2.png",256,256) 
//doorse("res/sei_ge_doa_kisimi02.wav")
{
	doorcount = 0;
	doordrawcount = 20;
	doorflag = 0;
	selected_door = 0;
}

CDoor::~CDoor()
{

}

void CDoor::Update()
{


	selected_door = 0;
	doorcount++;
	if (doorcount >= 0 & doorcount < doordrawcount)
	{
		//doorse.play();
		doorflag = 0;
	}
	else if (doorcount >= (doordrawcount)&& doorcount < (doordrawcount * 2))
		doorflag = 1;
	else if (doorcount >= (doordrawcount * 2) && doorcount < (doordrawcount * 3))
		doorflag = 2;
	else if (doorcount >= (doordrawcount * 3) && doorcount < (doordrawcount * 4))
		doorflag = 3;
	else if (doorcount >= (doordrawcount * 4) && doorcount < (doordrawcount * 5))
		doorflag = 4;

	else if (doorcount >= (doordrawcount * 5))
	{
		selected_door = 1;
		doorcount = 0;
		doorflag = 0;
		//doorse.stop();
	}
		
}

void CDoor::Draw()
{
	if (doorflag == 0)
		door01.DrawTextureBox(-120, -112, 256, 256, 0, 0, 172, 223, Color(1, 1, 1,1));

	if (doorflag == 1)
		door02.DrawTextureBox(-120, -112, 256, 256, 0, 0, 172, 223, Color(1, 1, 1, 1));

	if (doorflag == 2)
		door03.DrawTextureBox(-120, -112, 256, 256, 0, 0, 172, 223, Color(1, 1, 1, 1));

	if (doorflag == 3)
		door04.DrawTextureBox(-120, -112, 256, 256, 0, 0, 172, 223, Color(1, 1, 1, 1));

	if (doorflag == 4)
		door05.DrawTextureBox(-120, -112, 256, 256, 0, 0, 172, 223, Color(1, 1, 1, 1));
}