#include "NewtonFormula.h"

int NewtonFormula::set(const ScalarFunction& _f, std::vector<double> _A) {
	double fx,x;
	int l = _A.size();
	std::vector<double> B;
	std::vector<double>::iterator itb;
	std::vector<double>::iterator ita = _A.begin();
	for(int i = 0; i != l; i++) {
		B.push_back(_f( *(ita + i)));
	}
	for(int i = 1;i != l; i++) {
		ita = _A.end() - 1;
		for(itb = B.end() - 1; itb != B.begin() + i - 1; itb--) {
			fx = (*itb - *(itb - 1));
			x = *ita - *(ita - i);
			*itb = fx / x;
			ita--;
		}
	}
	__B = B;
	__flag = 1;
	return 0;
};

double NewtonFormula::pn(std::vector<double> _A, double _x) {
	if(__flag != 1) {
		std::cerr << "Unsetted" << std::endl;
		std::exit(-1);
	}
	double x,fx;
	x = 1;
	int l = _A.size();
	fx = 0;
	for(int i = 0; i != l; i++) {
		fx = fx + __B[i]*x;
		x = x*(_x - _A[i]);
	}
	return fx;
};
