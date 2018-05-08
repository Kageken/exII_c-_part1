/*
 * vector2d.h
 * 2次元ベクトル型(C++版)
 *
 */

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>

/* 2次元ベクトル型 */
class vector2d_s {
/*
 *  以下のように明示的に private, public を指定した場合は struct vector2d と宣言しても同じである
 */

private:
  double aval, bval, cval, dval;

public:
	/* デフォルトコンストラクタ */
	vector2d_s() { }

	/* 初期化引数つきコンストラクタ */
	vector2d_s(double a, double b, double c, double d){
	  aval = a;
	  bval = b;
	  cval = c;
	  dval = d;
	}

	double a() const { return aval; }
	double b() const { return bval; }
	double c() const { return cval; }
	double d() const { return dval; }

	double a(double a) { return aval = a; }
	double b(double b) { return bval = b; }
	double c(double c) { return cval = c; }
	double d(double d) { return dval = d; }

	/* x, y を与えて自身 = (x, y) にする */
	void set(double a, double b, double c, double d);

	/* x, y を与えて自身 = (v.x, v.y) にする */
	void set(vector2d_s v);

	/* 自身と v を加えたベクトルを返す */
	vector2d_s add(const vector2d_s & v);

	/* 減算メンバ */
	vector2d_s minus(const vector2d_s & v);

	vector2d_s pow(const vector2d_s & v);

	/* 文字列から浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
	char * readFrom(char *);

	/* ストリームから浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
	std::istream & readFrom(std::istream &);

	/* ベクトル v の値をファイルストリームに出力する */
	std::ostream & printOn(std::ostream &) const;

	/* ストリーム出力演算子 */
	friend std::ostream & operator<<(std::ostream & os, const vector2d_s & v) {
		return v.printOn(os);
	}
};

#endif /* _VECTOR2D_H_ */
