#include "Collision.h"

//	--------------------------------------------------------------------
//	objA��objB���Փ˂��Ă��邩�𒲂ׂ�
//	�����FOBJECT objA,objB...�Փ˔��肵�����I�u�W�F�N�g
//	�߂�l�Ftrue...�Փ˂��Ă��� false...�Փ˂��Ă��Ȃ�
//	--------------------------------------------------------------------
bool Collision::IsHit(float x_1, float y_1, float width_1, float height_1, float x_2, float y_2, float width_2, float height_2)
{

	float x0 = x_1;
	float y0 = y_1;
	float x1 = x_1 + width_1;
	float y1 = y_1 + height_1;

	float x2 = x_2;
	float y2 = y_2;
	float x3 = x_2 + width_2;
	float y3 = y_2 + height_2;

	//	��̋�`����������̌`�ŏd�Ȃ��Ă��邩�H
	if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
	{
		//	�d�Ȃ��Ă���
		return true;
	}

	//	�d�Ȃ��ĂȂ�����
	return false;

}