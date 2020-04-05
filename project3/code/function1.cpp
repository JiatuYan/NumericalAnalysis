#include "function1.h"

double function1::operator()(double x) const {
	double t;
	t = 1/(1+x*x);
	return t;
};
