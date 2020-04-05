#include "function2.h"

double function2::operator()(double x) const {
	double t;
	t = 1/(1+25*x*x);
	return t;
};
