#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//
#include "CRectangle.h"
/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer : public CRectangle {
public:
	bool mGameOver;
	bool mGameClear;
	int Life;
	float mFx, mFy;
	static CPlayer *spInstance;
	CPlayer();
	//更新処理
	void Update();
	//描画処理
	void Render();

	//衝突処理
	void Collision(CRectangle*i, CRectangle *y);
};

#endif

