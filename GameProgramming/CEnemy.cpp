#include "CEnemy.h"
#include "CTexture.h"

//extern : 他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
CEnemy::CEnemy()
:mFx(1.0f), mFy(1.0f)
{
	mTag = EENEMY;
	w = 25;
	h = 25;
}

//更新処理
void CEnemy::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	x += mFx;
	y += mFx;
}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
void CEnemy::Collision(CRectangle &r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			int mx, my;
			if (CRectangle::Collision(&r, &mx, &my)) {
				//abs(x) xの絶対値を求める
				//移動量が少ない方向だけ移動させる
				if (abs(mx) < abs(my)) {
					//Rectをxだけ移動する
					x += mx; mFx *= -1;
				}
				else{
					y += my; mFy *= 0;
				}
			}
			//衝突していれば反転
			break;
		}
		return ;
	}
	return ;
}

void CEnemy::Render(){
	if (mEnabled){
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

void CEnemy::Collision(CRectangle *i, CRectangle *y){
	Collision(*y);
}