#ifndef CENEMY_H
#define CENEMY_H

#include "CRectangle.h"

class CEnemy : public CRectangle {
public:
//	int HP;

	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�

	int mFireCount;

	CEnemy();

	void Update();
	void Collision(CRectangle &r);
	void Render();

	void Collision(CRectangle *i, CRectangle *y);
};

#endif
