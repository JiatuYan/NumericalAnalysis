#include "ScalarFunction.h"

class function1: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = std::sin(x / 2) - 1;
		return t;
	};
};

