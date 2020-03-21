#include "function4.h"

double function4::operator()(double x) const {
	double p, q;
	double x3 = x*x*x;
	double x2 = x*x;
	p = x3 + 4 * x2 + 3 * x + 5;
	q = 2 * x3 - 9 * x2 + 18 * x - 2;
	if(q == 0.0) {
		return MAX;
	}
	else {
		return p/q;
	}
};
