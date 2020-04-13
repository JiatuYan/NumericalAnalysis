#include "CubicSpline.h"

int CubicSpline::setM(double *_B) {
	if(__M.size() != 0) {
		__M.clear();
	}	
	for(int i = 0; i != __N; i++) {
		if(i == 0 || i == __N - 1) {
			__M.push_back(0);
		}
		else {
			__M.push_back(*(_B + i - 1));
		}
	}
	return 0; 
};

int CubicSpline::setA(std::vector<double> _A) {
	if(__A.size() != 0) {
		__A.clear();
	}
	for(int i = 0; i != __N; i++) {
		__A.push_back(_A[i]);
	}
	return 0;
};

int CubicSpline::set(const ScalarFunction& f, std::vector<double> _A) {
	int _n = _A.size();
	__N = _n;
	setA(_A);
	double M[(_n - 2)*(_n - 2)];
	double B[_n-2];
	int t = 0;
	double f1,f2;
	if(_n == 3) {
		M[0] = 2;
	}
	else {
		for(int i = 2; i!= _n; i++) {
			t = (_n - 2)*(i-2)+(i-2);
			if(i == 2) {
				M[0] = 2;
				M[1] = (_A[2] - _A[1])/(_A[2] - _A[0]);
			}
			else if(i == _n - 1) {
				M[t] = 2;
				M[t - 1] = (_A[_n-2] - _A[_n-3])/(_A[_n-1] - _A[_n-3]); 
			}
			else {
				M[t] = 2;
				M[t + 1] = (_A[i] - _A[i - 1])/(_A[i] - _A[i - 2]);
				M[t - 1] = (_A[i - 1] - _A[i - 2])/(_A[i] - _A[i - 2]); 
			}
		}
	}
	for(int i = 1; i!= _n - 1; i++) {
		f1 = (f(_A[i + 1]) - f(_A[i]))/(_A[i + 1] - _A[i]);
		f2 = (f(_A[i]) - f(_A[i - 1]))/(_A[i] - _A[i - 1]);
		B[i-1] = 6*(f1 - f2)/(_A[i + 1] - _A[i - 1]); 
	}
	int ipiv[_n - 2];
	LAPACKE_dgesv(LAPACK_ROW_MAJOR, _n - 2 , 1, M, _n - 2, ipiv, B, _n - 2);
	setM(B);
	return 0;
};

double CubicSpline::interpolate(const ScalarFunction& f, double x) {
	if(x < __A[0] || x > __A[__N - 1]) {
		std::cerr << "Out of the range" << std::endl;
		std::exit(-1);
	}
	int t = 0;
	double y;
	double f1,f2,f3,f4,x1,x2;
	for(int i = 0; i != __N - 1; i++) {
		if(x >= __A[i] && x <= __A[i + 1] ) {
			t = i;
			break;
		}
	}
	x1 = __A[t + 1] - __A[t];
	x2 = x - __A[t];
	f1 = f(__A[t]);
	f2 = (f(__A[t + 1]) - f(__A[t]))/x1 - (__M[t + 1] + 2*__M[t])*x1/6;
	f2 = f2*x2;
	f3 = __M[t]*x2*x2/2;
	f4 = (__M[t + 1] - __M[t])*x2*x2*x2/x1/6;
	y = f1 + f2 + f3 + f4;
	return y;
};

double CubicSpline::Max(const ScalarFunction& f) {
	double max = 0;
	double f1 , x;
	for(int i = 0; i!= __N - 1; i++) {
		for(int j = 0; j != 10000; j++ ) {
			x = __A[i] + (__A[i + 1] - __A[i])*j/10000;
			f1 = fabs(f(x) - interpolate(f, x));
			if(max < f1) {
				max = f1;
			}
		}
	}
	return max;
};
