#ifndef AITEMU�QH
#define AITEMU_H

#include "CRectangle.h"

/*
CRectangle�N���X���p������

*/
class Aitemu : public CRectangle{
public:
	int mFx, mFy;    //�ړ���

	//�f�t�H���g�R���X�g���N�^
	Aitemu();
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif