#include "ScalarFunction.h"

class function1: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = std::exp(x) - std::tan(x);
		return t;
	};
};

