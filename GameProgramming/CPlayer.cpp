#include "CPlayer.h"
#include "CKey.h"
#include "CSceneGame.h"
#define ANICNT 30 //�A�j���[�V�����̐؂�ւ�

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
int CPlayer::Life = 3;
CPlayer::CPlayer()
: mFx(1.0f), mFy(1.0f)
, mAniCnt(0)
, mGameOver(false)
, mGameClear(false)
{
	mTag = EPLAYER;	//�^�O�̐ݒ�
	spInstance = this;
}

CPlayer*CPlayer::spInstance = 0;

//�X�V����
void CPlayer::Update() {
	if (mGameOver)
		return;

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
	//S�L�[���͂ŏ����
	if (CKey::Push('S')) {
		y -= 3;
		mFx = 0;
		mFy = -1;
	}
	//W�L�[���͂ŏ����
	if (CKey::Push('W')) {
		y += 3;
		mFx = 0;
		mFy = 1;
	}
}

void CPlayer::Render(){
	if (mGameOver)
		return;
	mAniCnt++;
	mAniCnt %= ANICNT;
	if (mAniCnt < ANICNT / 2)
	{
		if (mFx >= 0)
		{
			CRectangle::Render(Texture, 130, 162, 162, 130);
		}
		else
		{
			CRectangle::Render(Texture, 162, 130, 162, 130);
		}
	}
	else
	{
		if (mFx >= 0)
		{
			CRectangle::Render(Texture, 162, 194, 162, 130);
		}
		else
		{
			CRectangle::Render(Texture, 194, 162, 162, 130);
		}
	}
}

void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
	if (ry->mTag == EBLOCK){
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) x�̐�Βl�����߂�
			//�ړ��ʂ����Ȃ����������ړ�������
			if (abs(mx) < abs(my)) {
				//Rect��x�����ړ�����
				x += mx;
			}
			else {
				//Rect��y�����ړ�����
				y += my;
			}
		}
	}
}