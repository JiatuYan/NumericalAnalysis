/**
 * @file BSplines.h
 * @brief Interpolate the function by cubic B-splines
 * @author XDDD
 * @version 
 * @date 2020-04-19
 */

#ifndef __PAISLEYPARK__CUBICBSPLINES__
#define __PAISLEYPARK__CUBICBSPLINES__

#include "ScalarFunction.h"

class CubicBsplines {
public:
	double Bspline(int i, double x);
	int setA(std::vector<double> _A);
	int set(const ScalarFunction& _f1, const ScalarFunction& _f2, double _x1, double _x2);
	double interpolate(double _x);
private:
	int __N;
	std::vector<double> __A;
	double __delta;
};

#else
//Do nothing
#endif
