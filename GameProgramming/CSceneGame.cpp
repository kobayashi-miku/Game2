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
	配列の要素分繰り返す
	配列名.size()
	配列の要素数を取得する
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		配列の参照
		配列名[添え字]
		通常の配列同様に添え字で要素にアクセスできる
		*/
		//更新処理
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//衝突処理
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//リストから削除する
	//イテレータの生成
	std::vector<CRectangle*>::iterator itr;
	//イテレータを先頭
	itr = VectorRect.begin();
	//最後まで繰り返し
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//次へ
			itr++;
		}
		else {
			//falseのインスタンスを削除
			delete *itr;
			//リストからも削除
			itr = VectorRect.erase(itr);
		}
	}
	//線画範囲変数の作成　範囲下：－300　範囲上：300　　固定
	double mLeft, mRight, mBottom = -300.0, mTop = 300.0;
	//画面範囲左の設定
	mLeft = CPlayer::spInstance->x - 400.0;
	//画面範囲右の設定
	mRight = mLeft + 800.0f;
	//画面投影範囲の変更
	//行列をプロジェクションモードへ変更
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   //行列を初期化
	//２Dの画面を設定
	gluOrtho2D(mLeft, mRight, mBottom, mTop);
	//行列をモデルビューモードへ変更
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //行列を初期化
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //白
	for (int i = 0; i < VectorRect.size(); i++) {
		//描画処理
		VectorRect[i]->Render();
	}
	//文字列の描画
	CText::DrawString("zanki", CPlayer::spInstance->x + 170, 250, 16, 16);

	if (CPlayer::spInstance->mGameOver){
		CText::DrawString("GameOver", CPlayer::spInstance->x, 0, 8, 16);
		CText::DrawString("Push ENTER Key",
			CPlayer::spInstance->x, -100, 8, 16);
	}
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはタイトル
		mScene = ETITLE;
	}

	//整数を文字列に変換する
	char buf[10];//９文字までOK
	sprintf(buf, "%d", e);
	CText::DrawString(buf, CPlayer::spInstance->x + 340, 250, 16, 16);

	CText::DrawString("Player", CPlayer::spInstance->x + 120, -250, 16, 16);


	//整数を文字列に変換する
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
			//次のシーンはタイトル
			mScene = ETITLE;
		}
	}
}

//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}

//デストラクタ
CSceneGame::~CSceneGame() {
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();
}


