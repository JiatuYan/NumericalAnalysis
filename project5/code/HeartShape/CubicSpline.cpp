#include "CubicSpline.h"

int CubicSpline::setM(double _x1, double _x2, double *_B) {
	if(__M.size() != 0) {
		__M.clear();
	}	
	for(int i = 0; i != __N; i++) {
		if(i == 0) {
			__M.push_back(_x1);
		}
		else if(i == __N - 1) {
			__M.push_back(_x2);
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

int CubicSpline::set(const ScalarFunction& f, double _x1, double _x2, std::vector<double> _A) {
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
				M[t - 1] = (_A[_n-3] - _A[_n-4])/(_A[_n-2] - _A[_n-4]); 
			}
			else {
				M[t] = 2;
				M[t + 1] = (_A[i+1] - _A[i])/(_A[i+1] - _A[i - 1]);
				M[t - 1] = (_A[i - 1] - _A[i - 2])/(_A[i] - _A[i - 2]); 
			}
		}
	}
	for(int i = 2; i!= _n; i++) {
		f1 = (f(_A[i]) - f(_A[i - 1]))/(_A[i] - _A[i - 1]);
		f2 = (f(_A[i - 1]) - f(_A[i - 2]))/(_A[i - 1] - _A[i - 2]);
		B[i-1] = 3*(_A[i - 1] - _A[i - 2])/(_A[i] - _A[i - 2])*f1 + 3*(_A[i] - _A[i - 1])/(_A[i] - _A[i - 2]); 
	}
	int ipiv[_n - 2];
	LAPACKE_dgesv(LAPACK_COL_MAJOR, _n - 2 , 1, M, _n - 2, ipiv, B, _n - 2);
	setM(_x1,_x2,B);
	return 0;
};

double CubicSpline::interpolate(const ScalarFunction& f, double x) {
	if(x < __A[0] || x > __A[__N - 1]) {
		std::cerr << "Out of the range" << std::endl;
		std::exit(-1);
	}
	int t = 0;
	double y;
	double x1,x2,K;
	for(int i = 0; i != __N - 1; i++) {
		if(x >= __A[i] && x <= __A[i + 1] ) {
			t = i;
			break;
		}
	}
	K = (f(__A[t+1]) - f(__A[t]))/(__A[t+1] - __A[t]);
	x1 = __A[t + 1] - __A[t];
	x2 = x - __A[t];
	y = (__M[t]+__M[t+1]-2*K)/x1/x1*(x - __A[t+1]);
	y = (y + (K-__M[t])/x1)*(x - __A[t]);
	y = (y + __M[t])*(x - __A[t]);
	y = y + f(__A[t]);
	return y;
};
