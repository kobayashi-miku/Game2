#ifndef AITEMUC�QH
#define AITEMUC_H

#include "CRectangle.h"

/*
CRectangle�N���X���p������

*/
class AitemuC : public CRectangle{
public:
	int mFx, mFy;    //�ړ���

	//�f�t�H���g�R���X�g���N�^
	AitemuC();
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif