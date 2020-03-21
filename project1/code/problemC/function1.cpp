#include "function1.h"

double function1::operator()(double x) const {
	double t;
	t = std::sin(x / 2) - 1;
	return t;
};
