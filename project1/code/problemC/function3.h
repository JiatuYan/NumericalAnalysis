#include "ScalarFunction.h"

class function1: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		double a = x*x; 
		t = x*a - 12*a + 3*x + 1;
		return t;
	};
};

