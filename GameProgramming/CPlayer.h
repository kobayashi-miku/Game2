#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//
#include "CRectangle.h"
/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter {
public:
	static CPlayer *spThis;
	CPlayer();
	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	//�Փˏ���
	void Collision(CRectangle*i, CRectangle *y);
};

#endif

