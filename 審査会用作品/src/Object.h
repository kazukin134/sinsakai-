#pragma once
#include "Collision.h"
#include "lib\Texture.h"
class Object
{

public:


	float x;			//x座標
	float y;			//y座標
	float width;		//幅
	float height;		//高さ

	float stage_x;		//マップx座標
	float stage_y;		//マップy座標
	float start_x;		//最初のx座標
	float start_y;		//最初のy座標

	float scroll_x;		//スクロール
	float speed = 3;		//速度
	float velocity_x;	//x速度
	float velocity_y;	//y速度
	const float margin = 64;  //足場
	float fall;			//落とし穴に当たった時に落ちる距離
	bool hitfear;		//敵に当たった時の恐怖ゲージのフラグ
	float choice_game;  //選択していることが分かるように左に動かす (ゲーム本編)
	float choice_title; //選択していることが分かるように左に動かす (タイトル)
	float choice_rule;  //選択していることが分かるように左に動かす (ルール)
	float choice_end;   //選択していることが分かるように左に動かす (終了)
	float disp_x;			//表示するx座標
	float movecount;		//スクロールのためのカウント

	//Eigen::Vector2i window_size = Eigen::Vector2i(window_width, window_height);//windowのサイズを取れるようにした

};