#include "AitemuC.h"
#include "CPlayer.h"
extern CTexture Texture;

//デフォルトコンストラクタ
AitemuC::AitemuC(){

}

//更新処理
void AitemuC::Update(){

}

//描画処理
void AitemuC::Render(){
	CRectangle::Render(Texture, 253, 242, 16, 1);
}

void AitemuC::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
			//			CPlayer::スコア=CPlayer::スコア+300;
			break;
		}
	}
}