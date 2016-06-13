#include "Matrix.h"


//// ��]�A�X�P�[�����O�A���s�ړ�����ϊ��s��𐶐�(2D����)
// rotate    ��]��(���W�A��)
// transtate ���s�ړ���
// scaling   �X�P�[�����O
 Affinef transformMatrix2D(const float rotate_rad, const Eigen::Vector3f& transtate, const Eigen::Vector3f& scaling) {
	Affinef matrix;

	Translation t(transtate);
	Scaling s(scaling);
	Quatf r(Eigen::AngleAxisf(rotate_rad, Eigen::Vector3f::UnitZ()));

	matrix = t * r * s;

	return matrix;
}