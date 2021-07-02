#include "CEnemy.h"
#include "CTexture.h"

//extern : ���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
CEnemy::CEnemy()
:mFx(1.0f), mFy(1.0f)
{
	mTag = EENEMY;
	w = 25;
	h = 25;
}

//�X�V����
void CEnemy::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	x += mFx;
	y += mFx;
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
void CEnemy::Collision(CRectangle &r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			int mx, my;
			if (CRectangle::Collision(&r, &mx, &my)) {
				//abs(x) x�̐�Βl�����߂�
				//�ړ��ʂ����Ȃ����������ړ�������
				if (abs(mx) < abs(my)) {
					//Rect��x�����ړ�����
					x += mx; mFx *= -1;
				}
				else{
					y += my; mFy *= 0;
				}
			}
			//�Փ˂��Ă���Δ��]
			break;
		}
		return ;
	}
	return ;
}

void CEnemy::Render(){
	if (mEnabled){
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

void CEnemy::Collision(CRectangle *i, CRectangle *y){
	Collision(*y);
}