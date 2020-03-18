#include "ScalarFunction.h"

class SecantMethod {
public:
	double solve(ScalarFunction& _f, double _x0, double _x1);
	int set(double _e, double _fe, int _t);
	SecantMethod(){};
	SecantMethod(double _e, double _fe, int _t);
	int num();
private:
	double __error = 0.00001;
	double __ferror = 0.00001;
	int __T = 100;
	int __num = 0;
}; 

double SecantMethod::solve(ScalarFunction& _f, double _x0, double _x1){
	double x_n = _x1;
	double x_n_1 = _x0;
	double u = _f(x_n);
	double v = _f(x_n_1);
	double t;
	double s;
	__num = 0;
	for(int i = 2; i != __T; i++) {
		if(fabs(u) > fabs(v)) {
			t = u;
			u = v; 
			v = u;
			t = x_n;
			x_n = x_n_1;
			x_n_1 = t;
		}
		s = (x_n - x_n_1) / (u - v);
		x_n_1 = x_n;
		x_n = x_n - u*s;
		v = u;
		u = _f(x_n);
		__num++;
		if(fabs(x_n - x_n_1) < __error || fabs(u) < __ferror) {
			break;
		}
	}
	return x_n;
}; 

int	SecantMethod::set(double _e, double _fe, int _t){
	__error = _e;
	__ferror = _fe;
	__T = _t;
	return 0;
};

SecantMethod::SecantMethod(double _e, double _fe, int _t) {
	__error = _e;
	__ferror = _fe;
	__T = _t;
};

int SecantMethod::num() {
	return __num;
};


