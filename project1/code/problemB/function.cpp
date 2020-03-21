#include "function.h"

double function::operator()(double x) const {
	double t;
	t = x - std::tan(x);
	return t;
};

double functiond::operator()(double x) const {
	double t = std::cos(x);
	if(t == 0) {
		t = MAX;
	}
	else {
		t = 1 - 1/t/t;
	}
	return t;
};
