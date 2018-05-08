/*
 * vector2d.cpp
 * 2次元ベクトル型(C++版)
 *
 *
 */

#include <iostream>
#include <cstdlib>

#include "vector2d.h"

/* x, y を与えて自身を (x, y) にする */
void vector2d::set(double x, double y) {
	xval = x;
	yval = y;
}

/* v を与えて自身を (v.x, v.y) にする */
void vector2d::set(vector2d v) {
	xval = v.xval;
	yval = v.yval;
}

/* 自身と v を加えたベクトルを返す */
vector2d vector2d::add(const vector2d & v) {
	vector2d r(xval + v.xval, yval+v.yval);
	return r;
}

/* 減算したベクトルを返す */
vector2d vector2d::minus(const vector2d & v){
	vector2d r(xval - v.xval, yval - v.yval);
	return r;
}

/* 文字列から浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
char * vector2d::readFrom(char * str)
{
	xval = strtod(str, &str);
	if ( *str == ',' )
		str++;
	yval = strtod(str, &str);

	return str;
}

/* ストリームから浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
std::istream & vector2d::readFrom(std::istream & is)
{
  char c;
	is >> xval;
	c = is.get();
	if ( c != ',') {
	  is.putback(c);
	}
	is >> yval;
	return is;
}

/* ベクトル v の値をファイルストリームに出力する */
std::ostream & vector2d::printOn(std::ostream & os) const
{
	os << "(" << xval << ", " << yval << ")";
	return os;
}
