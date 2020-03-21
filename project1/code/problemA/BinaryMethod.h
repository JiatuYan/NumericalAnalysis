#include "ScalarFunction.h"

class BinaryMethod {
public:
	double solve(const ScalarFunction& f, double a, double b);
	int set_error(double e, double fe, int t);
	BinaryMethod(){};
	BinaryMethod(double e, double fe, int t);
	int num();
private:
	double __error = 0.00001;
	double __ferror = 0.00001;
	int __T = 100;
	int __num = 0;
};

int sgn(double a);


