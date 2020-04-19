/**
 * @file QuadraticBsplines.h
 * @brief Interpolate f by quadratic B-splines.
 * @author XDDD
 * @version 
 * @date 2020-04-19
 */
#ifndef __PAISLEYPARK__QUADRATICBSPLINES__
#define __PAISLEYPARK__QUADRATICBSPLINES__

#include "ScalarFunction.h"

class QuadraticBsplines {
public:
	double Bspline(int i, double x);
	int setA(std::vector<double> _A);
	int set(const ScalarFunction& _f, double _x1, double _x2);
	double interpolate(double _x);
private:
	int __N;
	std::vector<double> __A;
	double __delta;
};

#else
//Do nothing
#endif
