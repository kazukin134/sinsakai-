#include "Matrix.h"


//// 回転、スケーリング、平行移動から変換行列を生成(2D向け)
// rotate    回転量(ラジアン)
// transtate 平行移動量
// scaling   スケーリング
 Affinef transformMatrix2D(const float rotate_rad, const Eigen::Vector3f& transtate, const Eigen::Vector3f& scaling) {
	Affinef matrix;

	Translation t(transtate);
	Scaling s(scaling);
	Quatf r(Eigen::AngleAxisf(rotate_rad, Eigen::Vector3f::UnitZ()));

	matrix = t * r * s;

	return matrix;
}