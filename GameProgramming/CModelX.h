#ifndef CMODELX_H   //�C���N���[�h�J�[�h
#define CMODELX_H

#define MODEL_FILE "sample.blend.x"  //���̓t�@�C����

//�̈�J�����}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = 0;}

//�z��̃T�C�Y�擾���}�N����
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#include <vector>     //vector�N���X�̃C���N���[�h(���I�z��)
#include "CMatrix.h"  //�}�g���N�X�N���X�̃C���N���[�h
#include "CVector.h"
class CModelX;  //CModelX�N���X�̐錾


//CMesh�N���X�̒�`
class CMesh{
public:
	int mVertexNum;      //���_��
	CVector *mpVertex;   //���_�f�[�^
	int mFaceNum;        //�ʐ�
	int *mpVertexIndex;  //�ʂ��\�����钸�_�ԍ�
	//�R���X�g���N�^
	CMesh()
		:mVertexNum(0)
		, mpVertex(0)
		, mFaceNum(0)
		, mpVertexIndex(nullptr)
	{}
	//�f�X�g���N�^
	~CMesh(){
		SAFE_DELETE_ARRAY(mpVertex);
		SAFE_DELETE_ARRAY(mpVertexIndex);
	}
	//�ǂݍ��ݏ���
	void Init(CModelX *model);	
};

//CModelXFrame�N���X�̒�`
class CModelXFrame{
public:
	std::vector<CModelXFrame*> mChild; //�q�t���[���̔z��
	CMatrix mTransformMatrix;    //�ϊ��s��
	char* mpName;        //�t���[�����O
	int mIndex;          //�t���[���ԍ�
	//�R���X�g���N�^
	CModelXFrame(CModelX* model);
	//�f�X�g���N�^
	~CModelXFrame(){
		//�q�t���[����S�ĊJ������
		std::vector<CModelXFrame*>::iterator itr;
		for (itr = mChild.begin(); itr != mChild.end(); itr++){
			delete *itr;
		}
		//���O�̃G���A���������
		SAFE_DELETE_ARRAY(mpName);
	}
	CMesh mMesh;       //Mesh�f�[�^
};
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����Ŋm�F����
*/
class CModelX{
public:
	char* mpPointer;       //�ǂݍ��݈ʒu
	char mToken[1024];     //���o�����P��̗̈�
	std::vector<CModelXFrame*>mFrame;   //�t���[���̔z�u

	CModelX()
		:mpPointer(0)
	{}

	~CModelX(){
		if (mFrame.size() > 0)
		{
			delete mFrame[0];
		}
	}
	//�t�@�C���ǂݍ���
	void Load(char* file);
	//�P��̎��o��
	void GetToken();
	//�m�[�h�̓ǂݔ�΂�
	void SkipNode();
	//���������_�f�[�^�̎擾
	float GetFloatToken();
	//�����f�[�^�̎擾
	int GetIntToken();

};

#endif