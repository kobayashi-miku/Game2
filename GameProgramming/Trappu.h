#ifndef TRAPPU＿H
#define TRAPPU_H

#include "CRectangle.h"

/*
CRectangleクラスを継承する

*/
class Trappu: public CRectangle{
public:
	int Life;
	int mFx, mFy;    //移動量

	//デフォルトコンストラクタ
	Trappu();
	//更新処理
	void Update();

	//描画処理
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif