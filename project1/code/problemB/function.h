#include "ScalarFunction.h"

#define MAX 1000000

class function: public ScalarFunction {
public:
	double operator()(double x) const;
};

class functiond: public ScalarFunction {
public:
	double operator()(double x) const;
};
