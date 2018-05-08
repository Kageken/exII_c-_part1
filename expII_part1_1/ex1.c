/*
 * ex1.c - 2次元ベクトル型(C版)テストプログラム
 */

#include <stdio.h>
#include <stdlib.h>
#include "c_vector2d.h"

#define BUFSIZE 256
/*
 * main() - テストプログラム
 */
int main(int argc, char * argv[])
{
	char buf[BUFSIZE];
	vector2d a, b, t;

/* ベクトル a, b の入力 */
	printf("x, y for a:\n");
	fgets(buf, BUFSIZE, stdin);
	readFrom(&a, buf);
	printf("a = ");
	printOn(stdout, &a);
	printf("\n\n");

	printf("x, y for b:\n");
	fgets(buf, BUFSIZE, stdin);
	readFrom(&b, buf);
	printf("b = ");
	printOn(stdout, &b);
	printf("\n\n");

/* c = a + b を出力 */
	printf("a + b = ");
	t = add(&a, &b);
	printOn(stdout, &t);
	printf("\n");

	printf("a - b = ");
	t = minus(&a, &b);
	printOn(stdout, &t);
	printf("\n");

/* a + (2, 1) を出力 */
	printf("a + (2,1) = ");
	set(&b, 2, 1);
	t = add(&a, &b);
	printOn(stdout, &t);
	printf("\n");

	return EXIT_SUCCESS;
}
