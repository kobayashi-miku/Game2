#ifndef AITEMUB�QH
#define AITEMUB_H

#include "CRectangle.h"

/*
CRectangle�N���X���p������

*/
class AitemuB : public CRectangle{
public:
	int mFx, mFy;    //�ړ���

	//�f�t�H���g�R���X�g���N�^
	AitemuB();
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif