#include "Trappu.h"
#include "CPlayer.h"
extern CTexture Texture;

//デフォルトコンストラクタ
Trappu::Trappu(){

}

//更新処理
void Trappu::Update(){

}

//描画処理
void Trappu::Render(){
	CRectangle::Render(Texture, 191, 208, 0, 16);
}

void Trappu::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
//		   Life=Life-1;
			break;
		}
	}
}