#include "function2.h"

double function2::operator()(double x) const {
	double t;
	if(x == 0) {
		t = MAX;
	}
	else {
		t = 1/x - pow(2,x);
	}
	return t;
};
