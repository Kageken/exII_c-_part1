/*
 * ex2a.c - 2次元ベクトル型(C版)テストプログラム
 */

#include <iostream>
#include <cstdlib>

#include "vector2d_3.h"

#define BUFSIZE 256
/*
 * main() - テストプログラム
 */
int main(int argc, char * argv[])
{
	vector2d a;
	char buf[BUFSIZE];

	std::cout << "a = " << a << std::endl;

	vector2d b(5, 5);
	vector2d c(a);
	vector2d d(b);

	return EXIT_SUCCESS;
}
