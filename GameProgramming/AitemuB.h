#ifndef AITEMUB＿H
#define AITEMUB_H

#include "CRectangle.h"

/*
CRectangleクラスを継承する

*/
class AitemuB : public CRectangle{
public:
	int mFx, mFy;    //移動量

	//デフォルトコンストラクタ
	AitemuB();
	//更新処理
	void Update();

	//描画処理
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif