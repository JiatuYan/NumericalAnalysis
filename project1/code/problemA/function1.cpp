#include "function1.h"

double function1::operator()(double x) const {
	double t;
	if(x == 0) {
		t = MAX;
	}
	else if(x == M_PI_2) {
		t = -MAX;
	}
	else {
		t = 1/x - std::tan(x);
	}
	return t;
};
