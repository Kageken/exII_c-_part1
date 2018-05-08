//
// CardSet_ex8.cpp - トランプカードの集合型(C++版)
//	作者: 陰山賢太; 日付: 2018/04/26
//
#include <iostream>
#include <random>

#include "card_ex8.h"
#include "cardset_ex8.h"

CardSet::CardSet(void) {
	count = 0;
}

// target に等しいカードの cards 中の格納位置を返す( == count: ない)
int CardSet::find(const Card & target) {
	for (int i = 0; i < count; i++) {
		if (target.equals(cards[i]))
			return i;
	}
	return count;	// 見つからなかった
}

// rank が num に等しいカードの格納位置を返す(== count: ない)
int CardSet::find(const int number) {
	for (int i = 0; i < count; i++) {
		if (number == cards[i].rank())
			return i;
	}
	return count;	// 見つからなかった
}

// １デッキすべての(maxnumcard 枚の)カードを入れる
void CardSet::setupDeck(void) {
	Card c;
	int suit, num;

	for (suit = Card::SUIT_SPADE; suit <= Card::SUIT_CLUB; suit++)
		for (num = 1; num <= 13; num++) {
			c.set(suit, num);
			insert(c);
		}
	c.set(Card::SUIT_JOKER, 0);
	insert(c);
}

// targetpos 枚目のカードを除き，そのカードを card で返す
// (false: 要素数に変化なし，card の値は変更されない; true: 成功)
//
// CardSet::remove() を実装した後に，コメントを外して draw を使えるようにせよ
bool CardSet::draw(Card & card, int targetpos) {
	std::random_device rnd;

	if( targetpos == -1 )
		targetpos = rnd() % count;
	else if( count == 0 || !(targetpos < count) )
		return false;

	card = cards[targetpos];
	return remove(card);
}

//
// CardSet::insert() - newcard を入れる (false: 要素数に変化なし; true: 追加成功)
//
bool CardSet::insert(const Card & newcard) {
	int position = find(newcard);
	if (position != count)
		return false;	// 既にある
	// 最後に追加
	if (count >= maxnumcard)
		return false; // もうはいらないし，入れられるカードはないはず
	position = count;
	count++;
	cards[position] = newcard;

	return true;
}

bool CardSet::remove(const Card & target){
  int position = find(target);
  if(position == count){
    return false;
  }
  for(int i = position; i < count; i++){
    cards[i] = cards[i+1];
  }
  count--;
  return true;
}

bool CardSet::remove(int num){
  int position = find(num);
  if(position == count){
    return false;
  }
  for(int i = position; i < count; i++){
    cards[i] = cards[i+1];
  }
  count--;
  return true;
}

// シャフルする
void CardSet::shuffle(void) {
	std::random_device rnd;
    int t, i, j, k;
    Card swap;

    for (t = 0; t < 100; t++) {
      i = rnd() % count;
      j = i + (rnd() % (count-i));
      for (k = 0; i + k < j; k++) {
    	  swap = cards[k];
    	  cards[k] = cards[j-k - 1];
    	  cards[j-k - 1] = swap;
       }
    }
}

// rank と suit で昇順にソートする
void CardSet::sort() {
	Card t;
	for(int i = 0; i < count - 1; ++i) {
		for(int j = i+1; j < count; ++j) {
			if ( cards[i].rank() > cards[j].rank()
					|| (cards[i].rank() == cards[j].rank() && cards[i].suit() > cards[j].suit())) {
				t = cards[j];
				cards[j] = cards[i];
				cards[i] = t;
			}
		}
	}
}

int CardSet::countCards(){
	return count;
}

//
// CardSet::print() - 自身を出力する
//
std::ostream& CardSet::printOn(std::ostream & out, const bool faceup) const {
	out << "CardSet";
	out << "{";
	if (count == 0) {
		out << " } ";
		return out;
	}
	for (int i = 0; i < count; i++) {
		cards[i].printOn(out, faceup);
		out << ", ";
	}
	out << "} ";
	return out;
}
