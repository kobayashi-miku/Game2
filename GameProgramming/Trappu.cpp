#include "Trappu.h"
#include "CPlayer.h"
extern CTexture Texture;

//�f�t�H���g�R���X�g���N�^
Trappu::Trappu(){

}

//�X�V����
void Trappu::Update(){

}

//�`�揈��
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