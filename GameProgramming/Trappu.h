#ifndef TRAPPU�QH
#define TRAPPU_H

#include "CRectangle.h"

/*
CRectangle�N���X���p������

*/
class Trappu: public CRectangle{
public:
	int mFx, mFy;    //�ړ���

	//�f�t�H���g�R���X�g���N�^
	Trappu();
	//�X�V����
	void Update();

	//�`�揈��
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif