//
// babastate_ex10.cc - ババ抜きの状態型(C++版): 人間参加版
//	作者: 陰山賢太; 日付: 2018/04/19
//

#include <iostream>

#include "babastate.h"

//
// BabaState::reset() - ゲーム開始直前の状態にリセット(カードを配った直後の状態にする)
//
void BabaState::reset(void) {
	// 各プレーヤの持ち手を空にする
	for (int i = 0; i < numplayer; i++) {
		hand[i].makeEmpty();
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
		hand[pindex].insert(c);
		// pindex を次のプレーヤにする．カードをくばる対象は全員
		pindex = (pindex + numplayer - 1) % numplayer;
	}
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
  if(to == 0){  // プレイヤーの手番
    int num;
    std::cout << "Player's turn" << std::endl;
    while(1){
    	std::cout << "Input draw num[0 - " << hand[from].countCards()-1 << "] : ";
    	std::cin >> num;
    	if(num >= 0 && num < hand[from].countCards()){
    		break;
    	}
    	std::cout << "無効な値です" << std::endl << std::endl;
    }
    hand[from].draw(c, num);
    hand[to].insert(c);
  }
  else{  // CPUの手番
    hand[from].draw(c, -1);
    hand[to].insert(c);
  }
  return c;
}

void BabaState::wastePair(int pindex) {
	Card c, d;
	int reps;
	int hand_size = hand[pindex].size();
	for(reps = 0; reps < hand_size; ++reps) {
		// 人間風にペアを見つけるのを繰り返す
		for(int i = 0; i < hand[pindex].size() - 1; ++i) {
			c = hand[pindex].at(i);
			for(int j = i + 1; j < hand[pindex].size(); ++j) {
				d = hand[pindex].at(j);
				if ( c.rank() == d.rank() ) {
					hand[pindex].remove(c);
					hand[pindex].remove(d);
					std::cout << c << "と" << d << "を捨てた" << std::endl << std::endl;
					break;
				}
			}
			if ( c.rank() == d.rank() )
				break;
		}
	}
	return;
}

// まだ手札を持っているプレーヤーの数
int BabaState::countPlaying() const {
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
		if ( i == 0 ) {
			hand[i].printOn(out, true); // PLAYER 0 は「自分」
		}
		else{
			hand[i].printOn(out, false);
		}
		out << ", " << std::endl;
	}
	return out;
}
