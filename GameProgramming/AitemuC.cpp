#include "AitemuC.h"
#include "CPlayer.h"
extern CTexture Texture;

//�f�t�H���g�R���X�g���N�^
AitemuC::AitemuC(){

}

//�X�V����
void AitemuC::Update(){

}

//�`�揈��
void AitemuC::Render(){
	CRectangle::Render(Texture, 253, 242, 16, 1);
}

void AitemuC::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
			//			CPlayer::�X�R�A=CPlayer::�X�R�A+300;
			break;
		}
	}
}