#include "ScalarFunction.h"

#define MAX 1000000

class function1: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		if(x == 0) {
			t = MAX;
		}
		else {
			t = 1/x - pow(2,x);
		}
		return t;
	};
};

