#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <GLFW/glfw3.h>



typedef Eigen::Quaternion<GLfloat> Quatf;
typedef Eigen::Translation<float, 3> Translation;
typedef Eigen::Transform< GLfloat, 3, Eigen::Affine> Affinef;

// FIXME:コンストラクタでx,y,z全て渡さないと初期値が未定義になる
typedef Eigen::DiagonalMatrix<GLfloat, 3> Scaling;

// 回転、スケーリング、平行移動から変換行列を生成(2D向け)
// rotate    回転量(ラジアン)
// transtate 平行移動量
// scaling   スケーリング
Affinef transformMatrix2D(const float rotate_rad, const Eigen::Vector3f& transtate, const Eigen::Vector3f& scaling);