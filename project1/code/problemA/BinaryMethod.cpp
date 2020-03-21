#include "BinaryMethod.h"

BinaryMethod::BinaryMethod(double e, double fe, int t) {
	__error = e;
	__ferror = fe;
	__T = t;
};

int BinaryMethod::set_error(double e, double fe, int t) {
	__error = e;
	__ferror = fe;
	__T = t;
	return 0;
};

double BinaryMethod::solve(const ScalarFunction& f, double a, double b) {
	if(a >= b) {
		std::cerr << "The [a, b] is not an interval" << std::endl;
		std::exit(-1);
	}
	__num = 0;
	double h = b - a;
	double c, w;
	double u = f(a);
	for(int i = 0; i!= __T; i++) {
		h = h/2;
		c = a + h;
		w = f(c);
		__num++;
		if(fabs(h) < __error || fabs(w) < __ferror) {
			break;
		}
		else if(sgn(w) == sgn(u)) {
			a = c;
		}
	}
	return c;
};

int BinaryMethod::num() {
	return __num;
};

int sgn(double a) {
	if(a>0) {
		return 1;
	}	
	else if (a==0) {
		return 0;
	}
	else {
		return -1;
	}
};

