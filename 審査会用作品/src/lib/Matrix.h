#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <GLFW/glfw3.h>



typedef Eigen::Quaternion<GLfloat> Quatf;
typedef Eigen::Translation<float, 3> Translation;
typedef Eigen::Transform< GLfloat, 3, Eigen::Affine> Affinef;

// FIXME:�R���X�g���N�^��x,y,z�S�ēn���Ȃ��Ə����l������`�ɂȂ�
typedef Eigen::DiagonalMatrix<GLfloat, 3> Scaling;

// ��]�A�X�P�[�����O�A���s�ړ�����ϊ��s��𐶐�(2D����)
// rotate    ��]��(���W�A��)
// transtate ���s�ړ���
// scaling   �X�P�[�����O
Affinef transformMatrix2D(const float rotate_rad, const Eigen::Vector3f& transtate, const Eigen::Vector3f& scaling);