//
// babastate.h - ババ抜きの状態型(C++版)
//	作者: 陰山賢太; 日付: 2018/04/26
//
#ifndef _BABASTATE_H_
#define _BABASTATE_H_

#include "card.h"
#include "cardset.h"

//
// BabaState - ババ抜きの状態型
//
class BabaState {
// 定義・宣言
public:
	static const int numplayer = 4;	// 総プレーヤ数

// メンバ変数
private:
	int cardOwner[53];

	int turnIndex;

// メンバ関数
public:
	// デフォルトコンストラクタ(初期値はカードを配った状態)
	BabaState(void)	{ reset(); }

	// リセット (ゲーム開始前のカードを配りおえた状態にする)
	// 0 番プレーヤーは最初にカードを引く
	void reset(void);

	// pindex 番のプレーヤが上がった(終了した)か否かの判定
	// (true: 上がった; false: まだ上がっていない)
	bool isFinished(int pindex);

	// ターンが回ってきた（カードを引く）プレーヤー
	int inTurn() const { return turnIndex; }

	// 次にターンが回ってくる（カードを取らせる）プレーヤー
	int nextTurn(void);

	// ターンを次のプレーヤーに回す
	bool goNext(void);

	// まだ手札を持っているプレーヤーの数
	int countPlaying(void);

	// 手札の数
	int countCards(int pindex);

	// fromPlayer 番のプレーヤから toPlayer 番のプレーヤにカードを渡す
	// 渡ったカード（の参照）を返す
	const Card move(int fromPlayer, int toPlayer);

	// pindex 番のプレーヤーの手札のペアをすべて捨てる
	void wastePair(int pindex);

	// 状態をストリームに出力する
	// player 0 以外のカードを伏せるには，第二引数に false を渡す．
	std::ostream & printOn(std::ostream & out, const bool faceup = true) const;
	friend std::ostream & operator<<(std::ostream & out, const BabaState & bs) {
		return bs.printOn(out);
	}
};

#endif
