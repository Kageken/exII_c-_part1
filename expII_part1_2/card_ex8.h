//
// card_ex8.h - トランプカードの型
//	作者:　陰山賢太; 日付: 2018/04/26
//
#ifndef _CARD_H_
#define _CARD_H_

#include <cstdio>
#include <iostream>
//
// Card - トランプカード型
//
class Card {
	// クラス定数
	// トランプの組(suit)のコード
	public:
	enum {
		SUIT_BLANK = 0,
		SUIT_SPADE = 1,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_CLUB,
		SUIT_JOKER,
	};
	
// メンバ変数
private:
//	インスタンスメンバ変数．Card 型データ（オブジェクト）がそれぞれ持っているデータ．
	int cardval;  // カードの情報

//	static は，クラスメンバのこと．Card クラスの中で共通の定数として Card::suitnames で参照できる．
//  クラス変数（定数）．値の初期化は .cpp で main の外に書いて行う
	static const char * suitnames[];
	static const char * ranknames[];

	static const int RANK_JOKER = 53; // Joker の rank 用ダーミー値

// メンバ関数
public:
	// デフォルトコンストラクタ（初期値はブランクカード）
	Card(void){
		cardval = 0;
	}

	Card(const char st, const int num) {
		cardval = 0;
		switch(st){
		case SUIT_CLUB:
			cardval += 13;
		case SUIT_DIAMOND:
			cardval += 13;
		case SUIT_HEART:
			cardval += 13;
		case SUIT_SPADE:
			cardval += num;
		}
	}

	Card(const Card & org) : cardval(org.cardval) { }

	// 組と番号を設定する
	void set(char st, int num) {
		cardval = 0;
		switch(st){
		case SUIT_CLUB:
			cardval += 13;
		case SUIT_DIAMOND:
			cardval += 13;
		case SUIT_HEART:
			cardval += 13;
		case SUIT_SPADE:
			cardval += num;
		}	
	}

	// アクセサ
	int rank(void) const {
		return cardval%13;
	}

	int suit(void) const {
		return (cardval/13)+1;
	}

	bool isValid() {
		if(cardval > 0 && cardval < 54){
			return true;
		}
		return false;
	}

	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// 同じアドレスにあるデータかどうか，ではない．
	bool equals(const Card & tgt) const {
		return cardval == tgt.cardval;
	}
	
	// 文字列から自身の値をセット
	const char * readFrom(const char *);
	
	/* ストリームか値をセット */
	std::istream & readFrom(std::istream &);

	/* ファイルストリームに出力する */
	std::ostream & printOn(std::ostream &, const bool faceup = true) const;

	/* ストリーム出力演算子 */
	friend std::ostream & operator<<(std::ostream & os, const Card & c) {
		return c.printOn(os);
	}
};
#endif
