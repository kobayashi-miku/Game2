#include "Aitemu.h"
#include "CPlayer.h"
extern CTexture Texture;
int CPlayer::sucoa;
//�f�t�H���g�R���X�g���N�^
Aitemu::Aitemu(){

}

//�X�V����
void Aitemu::Update(){

}

//�`�揈��
void Aitemu::Render(){
	CRectangle::Render(Texture, 237, 226, 31, 16);
}

void Aitemu::Collision(CRectangle *i, CRectangle *y){
	if (CRectangle::Collision(*y)){
		switch (y->mTag){
		case EPLAYER:
			mEnabled = false;
			CPlayer::sucoa=CPlayer::sucoa+100;
			break;
		}
	}
}