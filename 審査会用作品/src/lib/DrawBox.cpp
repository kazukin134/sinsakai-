#include "DrawBox.h"


void DrawFillBox(float x, float y, float width, float height,Color &color)
{


	const GLfloat vtx[] =
	{
		x, y,
		x, y + height,
		x + width, y + height,
		x + width, y,
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//頂点座標だけ許可(いちいち許可しなくちゃいけない)
	glEnableClientState(GL_VERTEX_ARRAY);

	//実際の描画部分
	glDrawArrays(GL_QUADS, 0, 4);

}
