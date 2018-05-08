/*
 * ex2a.c - 2次元ベクトル型(C版)テストプログラム
 */

#include <iostream>
#include <cstdlib>

#include "vector2d_4.h"

#define BUFSIZE 256
/*
 * main() - テストプログラム
 */
int main(int argc, char * argv[])
{
	vector2d_s a1, a2, t;
	char buf[BUFSIZE];

/* a, b, c, d の入力 */
	printf("a, b, c, d for a1:\n");
	std::cin.getline(buf, BUFSIZE);
	a1.readFrom(buf);
	printf("a1 = ");
	a1.printOn(std::cout);
	printf("\n");

	// std は標準ライブラリ，std::cout は，標準出力のこと．
	// << は，ファイルへの出力演算子．std::endl は，改行記号．
	std::cout << "a, b, c, d for a2:" << std::endl;
	a2.readFrom(std::cin);
	std::cout << "a2 = " << a2 << std::endl << std::endl;

/* a1 + b1 を出力 */
	t = a1.add(a2);
	std::cout << "a1 + a2 = " << t << std::endl;

/* a1 - a2 を出力 */
	t = a1.minus(a2);
	std::cout << "a1 - a2 = " << t << std::endl;

	t = a1.pow(a2);
	std::cout << "a1 * a2 = " << t << std::endl;

	return EXIT_SUCCESS;
}
