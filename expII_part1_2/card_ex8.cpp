//
// card_ex8.cpp - トランプカードの集合型(C++版)
//	作者: 陰山賢太; 日付: 2018/04/26
//
#include "card_ex8.h"

#include <iostream>

// クラス変数（定数）の初期化
const char * Card::suitnames[] = {
		"_", "S", "D", "H", "C", "Jkr",
//		"Blank", "Spade", "Diamond", "Heart", "Club", "Joker",
};

const char * Card::ranknames[] = {
  		"?", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "Jkr", "_",
};

//
// Card::scan() - 標準出力などから値を得る (true: 取得成功; false: 取得失敗)
//
const char * Card::readFrom(const char * str)
{
	char * ptr;
	int s;

	cardval = 0; // blank

  // 4組のいずれ？
  for(s = SUIT_SPADE; s <= SUIT_CLUB; s++) {
	  if( tolower(*str) == tolower(Card::suitnames[s][0]) ) { // 一文字目だけで判定
		  cardval = (s-1)*13;
		  do { ++str; } while ( isalpha(*str) );
		  break;
	  }
  }
  if ( SUIT_SPADE <= s && s <= SUIT_CLUB ) {
	  // なら番号も得る
	  while ( isspace(*str) ) { ++str; }
	  cardval += strtod(str, &ptr);
	  if ( 0 < cardval && cardval <= 52 ) {
		  return ptr;
	  }
  } else if( tolower(*str) == 'j' ) {
    cardval = RANK_JOKER; // joker は number を 53 としておく．
    do { ++str; } while ( isalpha(*str) );
    return str;
  }	std::istream & readFrom(std::istream &);
  return str;
}

std::istream & Card::readFrom(std::istream & in) {
	std::string buf;
	std::getline(in, buf);
	readFrom(buf.c_str());
	return in;
}

std::ostream & Card::printOn(std::ostream& ostr, const bool faceup) const {
	ostr << '[';
	if ( faceup ) {
		ostr << suitnames[((cardval-1)/13+1)];
		if ( ((cardval-1)/13+1) != SUIT_JOKER )
			ostr << " " << ranknames[((cardval-1)%13+1)];
	} else {
		ostr << "#";
	}
	ostr << ']';
	return ostr;
}

