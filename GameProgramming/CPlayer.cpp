#include "CPlayer.h"
#include "CKey.h"
#include "CSceneGame.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CPlayer::CPlayer()
: mFx(1.0f), mFy(1.0f)
{
	mTag = EPLAYER;	//タグの設定
	spInstance = this;
}
CPlayer*CPlayer::spInstance = 0;

//更新処理
void CPlayer::Update() {
	if (CKey::Push('A')) {
		x -= 3;
		mFx = -1;
		mFy = 0;
	}
	if (CKey::Push('D')) {
		x += 3;
		mFx = 1;
		mFy = 0;
	}
	//Sキー入力で上向き
	if (CKey::Push('S')) {
		y -= 3;
		mFx = 0;
		mFy = -1;
	}
	//Wキー入力で上向き
	if (CKey::Push('W')) {
		y += 3;
		mFx = 0;
		mFy = 1;
	}
}

void CPlayer::Render()
{
	CRectangle::Render(Texture, 146 - 16, 146 + 16, 146 + 16, 146 - 16);
}

void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
	if (ry->mTag == EBLOCK){
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) xの絶対値を求める
			//移動量が少ない方向だけ移動させる
			if (abs(mx) < abs(my)) {
				//Rectをxだけ移動する
				x += mx;
			}
			else {
				//Rectをyだけ移動する
				y += my;
			}
		}
	}
}