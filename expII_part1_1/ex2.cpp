/*
 * ex2a.c - 2次元ベクトル型(C版)テストプログラム
 */

#include <iostream>
#include <cstdlib>

#include "vector2d.h"

#define BUFSIZE 256
/*
 * main() - テストプログラム
 */
int main(int argc, char * argv[])
{
	vector2d a, b, t;
	char buf[BUFSIZE];

/* a, b の入力 */
	printf("x, y for a:\n");
	std::cin.getline(buf, BUFSIZE);
	a.readFrom(buf);
	printf("a = ");
	a.printOn(std::cout);
	printf("\n");

	// std は標準ライブラリ，std::cout は，標準出力のこと．
	// << は，ファイルへの出力演算子．std::endl は，改行記号．
	std::cout << "x, y for b:" << std::endl;
	b.readFrom(std::cin);
	std::cout << "b = " << b << std::endl << std::endl;

/* a + b を出力 */
	t = a.add(b);
	std::cout << "a + b = " << t << std::endl;

/* a - b を出力 */
	t = a.minus(b);
	std::cout << "a - b = " << t << std::endl;

/* a + (2, 1) を出力 */
	std::cout << "a + (2,1) = ";
	b.set(2,1);
	t.set(a);
	std::cout << t.add(b) << std::endl;

	return EXIT_SUCCESS;
}
