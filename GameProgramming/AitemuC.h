#ifndef AITEMUC＿H
#define AITEMUC_H

#include "CRectangle.h"

/*
CRectangleクラスを継承する

*/
class AitemuC : public CRectangle{
public:
	int mFx, mFy;    //移動量

	//デフォルトコンストラクタ
	AitemuC();
	//更新処理
	void Update();

	//描画処理
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif