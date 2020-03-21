#include "ScalarFunction.h"

#ifndef __PAISLEYPARK__SECANTMETHOD__
#define __PAISLEYPARK__SECANTMETHOD__

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

#else

#endif
