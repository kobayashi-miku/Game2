#include "AitemuB.h"
#include "CPlayer.h"
extern CTexture Texture;

//�f�t�H���g�R���X�g���N�^
AitemuB::AitemuB(){

}

//�X�V����
void AitemuB::Update(){

}

//�`�揈��
void AitemuB::Render(){
	CRectangle::Render(Texture, 239, 224, 15, 3);
}

void AitemuB::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
			CPlayer::sucoa=CPlayer::sucoa+200;
			break;
		}
	}
}