//
//
// cardsetextra.cc - トランプカードの集合型(C++版)テストプログラム
//	作者: 陰山賢太; 日付: 2018/04/19
//
#include <iostream>
#include <string>

#include "cardset.h"
#include "card.h"
//
// main() - トランプカードの集合型テストプログラム
//

int main (int argc, char * const argv[]) {
		Card c;
		CardSet cset;
		std::string buf;
		
		// 入力がカードとして解釈できない，または既に cset にあるカード
		// であればループを終了
		do {
			std::cout << cset << std::endl;
			std::cout << "Type 'suit number': ";
			c.readFrom(std::cin);
			if ( !c.isValid() )
				break;       // 正しいカードをスキャンできなかったらループを終了
			std::cout << c << std::endl;
		} while ( cset.insert(c) || cset.remove(c) );   // 追加されなかったらループを終了
		
		std::cout << "Sorting.";
		cset.sort();
		std::cout << std::endl;

		std::cout << "Removing(4).";
		cset.remove(4);
		std::cout << std::endl;

		std::cout << cset << std::endl;
		return 0;
}
