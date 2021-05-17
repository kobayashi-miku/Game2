#ifndef CMODELX_H    //�C���N���[�h�J�[�h
#define CMODELX_H

#define MODEL_FILE"sample.blend.x" //���̓t�@�C����

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a){if(a)delete[] a; a = 0;}
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����Ŋm�F����
*/
class CModel{
public:
	char* mpPointer;    //�ǂݍ��݈ʒu
	char mToken[1024];  //���o�����P��̗̈�

	CModelX()
		:mpPointer(0)
	{}
	//�t�@�C���ǂݍ���
	void Load(char* file);
};

#endif