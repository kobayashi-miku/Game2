#include "Aitemu.h"
#include "CPlayer.h"
extern CTexture Texture;

//デフォルトコンストラクタ
Aitemu::Aitemu(){

}

//更新処理
void Aitemu::Update(){

}

//描画処理
void Aitemu::Render(){
	CRectangle::Render(Texture, 237, 226, 31, 16);
}

void Aitemu::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
//			CPlayer::スコア=CPlayer::スコア+100;
			break;
		}
	}
}