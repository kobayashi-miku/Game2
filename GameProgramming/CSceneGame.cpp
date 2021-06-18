#include "CSceneGame.h"
#include "CTexture.h"
#include "CMap.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"



void CSceneGame::Init() {

}


void CSceneGame::Update() {
	/*
	�z��̗v�f���J��Ԃ�
	�z��.size()
	�z��̗v�f�����擾����
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		�z��̎Q��
		�z��[�Y����]
		�ʏ�̔z�񓯗l�ɓY�����ŗv�f�ɃA�N�Z�X�ł���
		*/
		//�X�V����
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//�Փˏ���
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//���X�g����폜����
	//�C�e���[�^�̐���
	std::vector<CRectangle*>::iterator itr;
	//�C�e���[�^��擪
	itr = VectorRect.begin();
	//�Ō�܂ŌJ��Ԃ�
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//����
			itr++;
		}
		else {
			//false�̃C���X�^���X���폜
			delete *itr;
			//���X�g������폜
			itr = VectorRect.erase(itr);
		}
	}
	//����͈͕ϐ��̍쐬�@�͈͉��F�|300�@�͈͏�F300�@�@�Œ�
	double mLeft, mRight, mBottom = -300.0, mTop = 300.0;
	//��ʔ͈͍��̐ݒ�
	mLeft = CPlayer::spInstance->x - 400.0;
	//��ʔ͈͉E�̐ݒ�
	mRight = mLeft + 800.0f;
	//��ʓ��e�͈͂̕ύX
	//�s����v���W�F�N�V�������[�h�֕ύX
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   //�s���������
	//�QD�̉�ʂ�ݒ�
	gluOrtho2D(mLeft, mRight, mBottom, mTop);
	//�s������f���r���[���[�h�֕ύX
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //�s���������
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //��
	for (int i = 0; i < VectorRect.size(); i++) {
		//�`�揈��
		VectorRect[i]->Render();
	}
	//������̕`��
	CText::DrawString("zanki", CPlayer::spInstance->x + 170, 250, 16, 16);

	if (CPlayer::spInstance->mGameOver){
		CText::DrawString("GameOver", CPlayer::spInstance->x, 0, 8, 16);
		CText::DrawString("Push ENTER Key",
			CPlayer::spInstance->x, -100, 8, 16);
	}
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓^�C�g��
		mScene = ETITLE;
	}

	//�����𕶎���ɕϊ�����
	char buf[10];//�X�����܂�OK
	sprintf(buf, "%d", e);
	CText::DrawString(buf, CPlayer::spInstance->x + 340, 250, 16, 16);

	CText::DrawString("Player", CPlayer::spInstance->x + 120, -250, 16, 16);


	//�����𕶎���ɕϊ�����
	sprintf(buf, "%d", CPlayer::spInstance->Life);
	CText::DrawString(buf, CPlayer::spInstance->x + 320, -250, 16, 16);



	if (CSceneGame::e == 0){
		CPlayer::spInstance->mGameClear = true;
		if (CPlayer::spInstance->mGameClear){
			CText::DrawString("GameClear", CPlayer::spInstance->x, 0, 8, 16);
			CText::DrawString("Push ENTER Key",
				CPlayer::spInstance->x, -100, 8, 16);
		}
		if (CKey::Once(VK_RETURN)) {
			//���̃V�[���̓^�C�g��
			mScene = ETITLE;
		}
	}
}

//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}

//�f�X�g���N�^
CSceneGame::~CSceneGame() {
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();
}


