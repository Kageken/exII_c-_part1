//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: 陰山賢太; 日付: 2018/04/19
//

#include <iostream>

#include "card.h"
#include "cardset.h"
#include "babastate_ex9.h"

//
// BabaState::reset() - ゲーム開始直前の状態にリセット(カードを配った直後の状態にする)
//
void BabaState::reset(void) {
	// 各プレーヤの持ち手を空にする
	for (int i = 0; i < 53; i++) {
		cardOwner[i] = -1;
	}
	turnIndex = 0;
	// デッキ(1セット)のカードを deck に入れる
	CardSet deck;
	deck.setupDeck();
	deck.shuffle();

	// 無くなるまでカードをとり pindex 番のプレーヤに配る
	// 配る順番は pindex が減る（ターンがまわるのと逆）向き
	int pindex = 0;	// 配る相手プレーヤ，最初にターンがくる（抜かれる）プレーヤーから
	Card c;		// 配るカード
	while (!deck.isEmpty()) {
		deck.draw(c, 0);
		// deck から一枚抜いてプレーヤーに渡す
		if(c.suit() == Card::SUIT_JOKER){
			cardOwner[52] = pindex;
		}else{
			cardOwner[(c.suit()-1)*13+c.rank()-1] = pindex;
	 	}
		// pindex を次のプレーヤにする．カードをくばる対象は全員
		pindex = (pindex + numplayer - 1) % numplayer;
	}
}

// 上がっているか判定
bool BabaState::isFinished(int pindex){
	for(int i = 0; i < 53; i++){
		if(cardOwner[i] == pindex){
			return false;
		}
	}
	return true;
}

// 次にターンが回ってくる（カードを取らせる）プレーヤー
int BabaState::nextTurn(void) {
	int next = turnIndex;
	do {
		next = (next + 1) % numplayer;
	} while (isFinished(next) && next != turnIndex);
	return next;
}

// ターンを次のプレーヤーに回す
bool BabaState::goNext() {
	int next = nextTurn();
	if ( next != turnIndex ) {
		turnIndex = next;
		return true;
	}
	return false; // 失敗
}

const Card BabaState::move(int from, int to){
  Card c;
  CardSet tmpdeck;
  int tmpindex;
  tmpdeck.setupDeck();
  tmpdeck.shuffle();
  for(int i = 0; i < 53; i++){
  	tmpdeck.draw(c, 0);
  	if(c.suit() == Card::SUIT_JOKER){
  		tmpindex = 52;
  	}else{
  		tmpindex = (c.suit()-1)*13+c.rank()-1;
  	}
  	if(cardOwner[tmpindex] == from){
  		cardOwner[tmpindex] = to;
  		break;
  	}
  }
  return c;
}

int BabaState::countCards(int pindex){
	int num = 0;
	for(int i = 0; i < 53; i++){
		if(cardOwner[i] == pindex){
			num++;
		}
	}
	return num;
}

void BabaState::wastePair(int pindex) {
	for(int i = 0; i < 52; i++){
		if(cardOwner[i] >= 0){ // 誰かが所有していれば
			for(int j = i%13; j < 52; j+=13){
				if(cardOwner[i] == cardOwner[j] && i != j){
					cardOwner[i] = -1;
					cardOwner[j] = -1;
					break;
				}
			}
		}
	}
}

// まだ手札を持っているプレーヤーの数
int BabaState::countPlaying() {
	int count = 0;
	for (int i = 0; i < numplayer; ++i) {
		if (!isFinished(i))
			++count;
	}
	return count;
}

// 状態をストリームに出力する
std::ostream & BabaState::printOn(std::ostream & out, const bool faceup) const {
	for (int i = 0; i < numplayer; i++) {
		out << "PLAYER " << i << ": ";
		for(int j = 0; j < 53; j++){
			if(cardOwner[j] == i){
				out << j << ", ";
			}
		}
		out << ", " << std::endl;
	}
	return out;
}
