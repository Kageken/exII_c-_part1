/*
 * vector2d.h
 * 2次元ベクトル型(C++版)
 *
 */

#ifndef _VECTOR2D_3_H_
#define _VECTOR2D_3_H_

#include <iostream>
#include <cstdio>

/* 2次元ベクトル型 */
class vector2d {
/*
 *  以下のように明示的に private, public を指定した場合は struct vector2d と宣言しても同じである
 */

private:
	double xval, yval; /* x 座標値, y 座標値 */

public:
	/* デフォルトコンストラクタ */
	vector2d() {
		xval = 7.0;
		yval = 7.0;
		printf("This is default const\n");
		printf("init > (%f, %f)\n", xval, yval);
	}

	/* 初期化引数つきコンストラクタ */
	vector2d(double x, double y) {
		xval = x;
		yval = y;
		printf("This is init const\n");
		printf("init> (%f, %f)\n", xval, yval);
	}

	vector2d(const vector2d & v){
	  xval = v.xval;
	  yval = v.yval;
	  printf("This is copy const\n");
	  printf("init> (%f, %f)\n", xval, yval);
	}

	double x() const { return xval; }
	double y() const { return yval; }

	double x(double x) { return xval = x; }
	double y(double y) { return yval = y; }

	/* x, y を与えて自身 = (x, y) にする */
	void set(double x, double y);

	/* x, y を与えて自身 = (v.x, v.y) にする */
	void set(vector2d v);

	/* 自身と v を加えたベクトルを返す */
	vector2d add(const vector2d & v);

	/* 減算メンバ */
	vector2d minus(const vector2d & v);

	/* 文字列から浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
	char * readFrom(char *);

	/* ストリームから浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
	std::istream & readFrom(std::istream &);

	/* ベクトル v の値をファイルストリームに出力する */
	std::ostream & printOn(std::ostream &) const;

	/* ストリーム出力演算子 */
	friend std::ostream & operator<<(std::ostream & os, const vector2d & v) {
		return v.printOn(os);
	}
};

#endif /* _VECTOR2D_3_H_ */
