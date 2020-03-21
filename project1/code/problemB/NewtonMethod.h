#include "ScalarFunction.h"

class NewtonMethod {
public:
	double solve(const ScalarFunction& _f, const ScalarFunction& _fd, double _x0);
	int set(double _e, int _t);
	int num();
	NewtonMethod(){};
	NewtonMethod(double _e, int _t);
private:
	double __error = 0.00001;
	double __T = 100;
	int __num = 0;
};

