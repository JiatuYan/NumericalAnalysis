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

NewtonMethod::NewtonMethod(double _e, int _t) {
	__error = _e;
	__T = _t;
};

int NewtonMethod::set(double _e, int _t) {
	if(_e <= 0 || _t <=0) {
		std::cerr << "Wrong postconditions"  << std::endl;
		std::exit(-1);
	} 
	__error = _e;
	__T = _t;
	return 0;
};

double NewtonMethod::solve(const ScalarFunction& _f
						, const ScalarFunction& _fd
						, double _x0) {
	__num = 0;
	double x = _x0;
	double u;
	for(int i = 0; i != __T; i++) {
		u = _f(x);
		if(fabs(u) < __error) {
			break;
		}
		__num++;
		x = x - u/(_fd(x));
	}
	return x;
};

int NewtonMethod::num() {
	return __num;
}
