/*
 * vector2d.h
 * 2次元ベクトル型(C++版)
 *
 */

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>

/* 2次元ベクトル型 */
class vector2d {
/*
 *  以下のように明示的に private, public を指定した場合は struct vector2d と宣言しても同じである
 */

private:
	double xval, yval; /* x 座標値, y 座標値 */

public:
	/* デフォルトコンストラクタ */
	vector2d() { }

	/* 初期化引数つきコンストラクタ */
	vector2d(double x, double y) {
		xval = x;
		yval = y;
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

#endif /* _VECTOR2D_H_ */
