/*
 * c_vector2d.h
 * 2次元ベクトル型(C版)
 *
 *  Created on: 2017/02/23
 *      Author: sin
 *
 *  Updated on: 2018/04/12
 *  	Author: kageyama
 */

/* この ifndef ~ endif は，
 * 一度インクルードされた定義を
 * 二度目以降は無視させるために
 * つけられています．
 * ifndef は if not defined の意味．
 * 二度目以降は _C_VECTOR2D_ という名前
 * が定義済みなので無視される
 */
#ifndef _C_VECTOR2D_H_
#define _C_VECTOR2D_H_

#include <stdio.h>

/* 2次元ベクトル型 */
struct vector2d {
	double x, y;
};
typedef struct vector2d vector2d;

/* プロトタイプ宣言 */

/* 値 x, y を与えて v = (x, y) にする */
void set(vector2d * v, double x, double y);

/* ベクトル u の各成分の値を v と同じにする */
void copy(vector2d * u, vector2d * v);

/* ベクトル u + v を作成して返す，u と v はポインタ参照で取り、変更しない */
vector2d add(vector2d * u, vector2d * v);

/* ベクトル u + v を行う　*/
vector2d minus(vector2d * u, vector2d * v);

/* 文字列から浮動小数点数を 2 つ読み，v の x, y 成分それぞれにセットする */
char * readFrom(vector2d * v, char * str);

/* ベクトル v の値をファイルストリームに出力する */
size_t printOn(FILE * fp, vector2d * v);


#endif /* C_VECTOR2D_H_ */
