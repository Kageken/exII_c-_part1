/*
 * vector2d_4.cpp
 * 2次元ベクトル型(C++版)
 *
 *
 */

#include <iostream>
#include <cstdlib>

#include "vector2d_5.h"

/* x, y を与えて自身を (x, y) にする */
void vector2d_s::set(double a, double b, double c, double d) {
	aval = a;
	bval = b;
	cval = c;
	dval = d;
}

/* v を与えて自身を (v.x, v.y) にする */
void vector2d_s::set(vector2d_s v) {
	aval = v.aval;
	bval = v.bval;
	cval = v.cval;
	dval = v.dval;
}

/* 自身と v を加えたベクトルを返す */
vector2d_s vector2d_s::add(const vector2d_s & v) {
  vector2d_s r(aval + v.aval, bval+v.bval, cval + v.cval, dval + v.dval);
	return r;
}

/* 減算したベクトルを返す */
vector2d_s vector2d_s::minus(const vector2d_s & v){
  vector2d_s r(aval - v.aval, bval - v.bval, cval - v.cval, dval - v.dval);
	return r;
}

vector2d_s vector2d_s::pow(const vector2d_s & v){
  vector2d_s r(aval*v.aval + bval*v.cval,
	       aval*v.bval + bval*v.dval,
	       cval*v.aval + dval*v.cval,
	       cval*v.bval + dval*v.dval);
  return r;
}

/* 文字列から浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
char * vector2d_s::readFrom(char * str)
{
	aval = strtod(str, &str);
	if ( *str == ',' )
		str++;
	bval = strtod(str, &str);
	if ( *str == ',' )
	  str++;
	cval = strtod(str, &str);
	if ( *str == ',' )
	  str++;
	dval = strtod(str, &str);

	return str;
}

/* ストリームから浮動小数点数を 2 つ読み，それぞれを成分の値としてセットする */
std::istream & vector2d_s::readFrom(std::istream & is)
{
  char c;
	is >> aval;
	c = is.get();
	if ( c != ',') {
	  is.putback(c);
	}
	is >> bval;
	c = is.get();
	if ( c != ',') {
	  is.putback(c);
	}
	is >> cval;
	c = is.get();
	if ( c != ',') {
	  is.putback(c);
	}
	is >> dval;

	return is;
}

/* ベクトル v の値をファイルストリームに出力する */
std::ostream & vector2d_s::printOn(std::ostream & os) const
{
  os << "((" << aval << ", " << bval << "),(" << cval << ", " << dval << "))";
	return os;
}
