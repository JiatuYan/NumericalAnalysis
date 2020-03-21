#include "function3.h"

double function3::operator()(double x) const {
	double t;
	t = pow(2, -x) + exp(x) + 2*std::cos(x) - 6;
	return t;
};
