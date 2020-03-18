#include "ScalarFunction.h"

#define MAX 1000000

class function: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = x - std::tan(x);
		return t;
	};
};

class functiond: public ScalarFunction {
public:
	double operator()(double x) const {
		double t = std::cos(x);
		if(t == 0) {
			t = MAX;
		}
		else {
			t = 1 - 1/t/t;
		}
		return t;
	};
};
