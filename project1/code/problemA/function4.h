#include "ScalarFunction.h"

#define MAX 1000000

class function4: public ScalarFunction {
public:
	double operator()(double x) const;
};

