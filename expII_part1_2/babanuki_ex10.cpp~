//
// babanuki1.cc - ババ抜きプログラム(C++版)
//	作者: 陰山賢太; 日付: 2018/04/19
//
#include "babastate.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

//
// main() - ババ抜きプログラム

int main(void) {
	char tmp[32];
	BabaState bstat;	// ババ抜きの状態
	int turn, next; // プレーヤーの番号用
	Card card;
	bool faceup = true;   // カードをおもてにするかとうか．false にすると，ゲームらしいかもしれない

	// 配り終えた状態の表示
	bstat.printOn(std::cout, faceup);
	std::cout << std::endl;

	// ペアをすべて捨てる
	for(int pindex = 0; pindex < bstat.numplayer; ++pindex)
		bstat.wastePair(pindex);
	// 最初の手札を整理し終わった状態の表示
	bstat.printOn(std::cout, faceup);
	std::cout << std::endl;

	// 終了条件になるまでカードを引き続ける
	// bstat.inTurn() 番のプレーヤーから次の bstat.nextTurn() 番のプレーヤーが
	// カードを引く
	while (bstat.countPlaying() > 1) {	// 最後の一人になるまで
		turn = bstat.inTurn();
		next = bstat.nextTurn();

		// turn 番のプレーヤから next 番のプレーヤがカードを一枚とる
		card = bstat.move(turn, next);
		std::cout << "# プレーヤ " << turn << " からプレーヤ " << next
				<< " がカード";
		card.printOn(std::cout, faceup);
		std::cout << "を取った" << std::endl << std::endl;
		bstat.wastePair(next);
		if ( bstat.countCards(turn) == 0 ) {
			std::cout << "# プレーヤ " << turn << "あがり．" << std::endl;
		}
		if ( bstat.countCards(next) == 0 ) {
			std::cout << "# プレーヤ " << next << "あがり．" << std::endl;
		}

		bstat.printOn(std::cout, faceup);
		std::cout << std::endl;

		// ターンを次にまわす
		bstat.goNext();

		std::cin.getline(tmp, 32); // return/enter されるまで待つ
	}

	std::cout << std::endl << "### FINISHED ###" << std::endl;

	return 0;
}

