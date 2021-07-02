#ifndef AITEMU＿H
#define AITEMU_H

#include "CRectangle.h"

/*
CRectangleクラスを継承する

*/
class Aitemu : public CRectangle{
public:
	int mFx, mFy;    //移動量

	//デフォルトコンストラクタ
	Aitemu();
	//更新処理
	void Update();

	//描画処理
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif