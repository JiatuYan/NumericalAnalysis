#include "function2.h"

double function2::operator()(double x) const {
	double t;
	t = std::exp(x) - std::tan(x);
	return t;
};
