#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	int e;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame();
};

#endif
