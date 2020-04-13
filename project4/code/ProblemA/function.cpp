#include "function.h"

double function::operator()(double x) const {
	double t;
	t = 1/(1+25*x*x);
	return t;
};
