#include "ScalarFunction.h"

class function3: public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = pow(2, -x) + exp(x) + 2*std::cos(x) - 6;
		return t;
	};
};

