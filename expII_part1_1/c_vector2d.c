/*
 * vector2c.c - 2次元ベクトル型(C版)
 *	作者: Kageyama Kenta; 日付: 2018/04/12
 */
#include <stdio.h>
#include <stdlib.h>
#include "c_vector2d.h"

/* 値 x, y を与えて v = (x, y) にする */
void set(vector2d * v, double x, double y) {
	v->x = x;
	v->y = y;
}

/* ベクトル u の各成分の値を v と同じにする */
void copy(vector2d * u, vector2d * v) {
	u->x = v->x;
	u->y = v->y;
}

/* 新しいベクトル u + v を作成して返す */
vector2d add(vector2d * u, vector2d * v) {
	vector2d r;
	r.x = u->x + v->x;
	r.y = u->y + v->y;
	return r;
}

vector2d minus(vector2d * u, vector2d * v){
	vector2d r;
	r.x = u->x - v->x;
	r.y = u->y - v->y;
	return r;
}

/* 文字列から浮動小数点数を 2 つ読み，v の x, y 成分それぞれにセットする */
char * readFrom(vector2d * v, char * str) {
	v->x = strtod(str, &str);
	if ( *str == ',' )
		str++;
	v->y = strtod(str, &str);
	return str;
}

/*
 * printOn() - ベクトル v の値を標準出力に出力する
 */
size_t printOn(FILE * fp, vector2d * v)
{
	return fprintf(fp, "(%f, %f)", v->x, v->y);
}
