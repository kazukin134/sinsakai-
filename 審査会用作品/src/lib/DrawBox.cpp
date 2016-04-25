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

	//���_���W��������(�������������Ȃ����Ⴂ���Ȃ�)
	glEnableClientState(GL_VERTEX_ARRAY);

	//���ۂ̕`�敔��
	glDrawArrays(GL_QUADS, 0, 4);

}
