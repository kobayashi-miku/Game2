#include "CSceneGame.h"
#include "CTexture.h"
#include "CMap.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include <stdio.h>
#include "Aitemu.h"
#include "AitemuB.h"
#include "AitemuC.h"
#include "Trappu.h"
int CSceneGame::e;


void CSceneGame::Init() {
	//シーンの設定
	mScene = EGAME;

	Texture.Load("Image.tga");
	//文字画像の読み込み
	CText::mFont.Load("font.tga");

	//クラスのメンバ変数への代入
	CPlayer *Player = new CPlayer();
	Player->x = 150;
	Player->y = 150;
	Player->w = 25;
	Player->h = 25;
	Player->mEnabled = true;

	int map[6][10] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 5, 0, 0, 0, 0, 6, 0, 0, 1 },
		{ 1, 0, 2, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 3, 0, 7, 0, 1 },
		{ 1, 4, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	e = 0;
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 100; i++) {
			//mapの要素が1の時、四角形配置
			if (map[j][i] == 1) {
				CMap *Map = new CMap();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 50;
				Map->h = 50;
			}
			else if (map[j][i] == 2) {
				e++;
				CEnemy *Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = 1;
				Enemy->mFy = 0;
			}
			else if (map[j][i] == 3) {
				e++;
				CEnemy *Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = 0;
				Enemy->mFy = 1;
				e = e + 1;
			}
			if (map[j][i] == 4) {
				Aitemu *Map = new Aitemu();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 40;
				Map->h = 40;
			}
			if (map[j][i] == 5) {
				AitemuB *Map = new AitemuB();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250 ;
				Map->w = 40;
				Map->h = 40;
			}
			if (map[j][i] == 6) {
				AitemuC *Map = new AitemuC();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 40;
				Map->h = 40;
			}
			if (map[j][i] == 7) {
				Trappu *Map = new Trappu();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 40;
				Map->h = 40;
			}
		}
	}
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

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //赤
	CText::DrawString("R:1.0 G:0.0 B:0.0 A:1.0", -380, 280, 8, 16);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //緑
	CText::DrawString("R:0.0 G:1.0 B:0.0 A:1.0", -380, 250, 8, 16);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //青
	CText::DrawString("R:0.0 G:0.0 B:1.0 A:1.0", -380, 220, 8, 16);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //白

	//文字列の描画
	CText::DrawString("zanki", CPlayer::spInstance->x + 170, 250, 16, 16);
	CText::DrawString("sucoa", CPlayer::spInstance->x + 270, 250, 16, 16);

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


