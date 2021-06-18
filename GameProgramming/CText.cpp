﻿#include "CText.h"

//staticのテクスチャのインスタンス
CTexture CText::mFont;
/*
DrawChar
文字を描画する
ch:文字データ x:X座標 y:Y座標 w:幅 h:高さ
*/
void CText::DrawChar(char ch, int x, int y, int w, int h) {
	int u = ch % 16 * 16;
	int v = (ch - ' ') / 16 * 16;
	mFont.DrawImage(x - w, x + w, y - h, y + h, u, u + 15, v + 15, v);
}
// s:文字列データ x:先頭文字X座標 y:先頭文字Y座標
void CText::DrawString(const char *s, int x, int y, int w, int h) {
	//1文字ずつ描画します
	for (int i = 0; s[i] != '\0'; i++) {
		//文字を描画する
		DrawChar(s[i], x, y, w, h);
		//右へ移動
		x += w * 2;
	}
}
