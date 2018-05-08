/*
 * ex2a.c - 2次元ベクトル型(C版)テストプログラム
 */

#include <iostream>
#include <cstdlib>

#include "vector2d_5.h"
#include "vector2d_3.h"

#define BUFSIZE 256
/*
 * main() - テストプログラム
 */
int main(int argc, char * argv[])
{
	vector2d_s a1, a2, t;
	char buf[BUFSIZE];
	vector2d b1, b2, s;

/* a, b の入力 */
	printf("a, b, c, d for a1:\n");
	std::cin.getline(buf, BUFSIZE);
	a1.readFrom(buf);
	printf("a1 = ");
	a1.printOn(std::cout);
	printf("\n");

	std::cout << "x, y for b1:" << std::endl;
	b1.readFrom(std::cin);
	std::cout << "b1 = " << b1 << std::endl;

	a2.set(2, 2, 2, 2);
	std::cout << "a2 = " << a2 << std::endl;
	b2.set(2, 2);
	std::cout << "b2 = " << b2 << std::endl;

/* a + b を出力 */
	t = a1.add(a2);
	std::cout << "a1 + a2 = " << t << std::endl;

/* a - b を出力 */
	t = a1.minus(a2);
	std::cout << "a1 - a2 = " << t << std::endl;

	t = a1.pow(a2);
	std::cout << "a1 * a2 = " << t << std::endl;

	s = b1.add(b2);
	std::cout << "b1 + b2 = " << s << std::endl;

	s = b1.minus(b2);
	std::cout << "b1 - b2 = " << s << std::endl;

	return EXIT_SUCCESS;
}
