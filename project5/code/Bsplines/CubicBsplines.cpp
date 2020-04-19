#include "CubicBsplines.h"

double CubicBsplines::Bspline(int i, double x){
	double t;
	if(i + 1 < x && x < i + 3) {
		x = 2.0 * i + 2.0 - x;
	}
	if(i - 1 < x && x <= i) {
		t = x - i + 1.0;
		t = t * t * t / 6.0;
	}
	else if(i < x && x <= i + 1) {
		t = (i + 1.0 - x) * (i + 1.0 - x);
		t = (x - i + 1.0) * t * 0.5;
		t = 2.0 / 3.0 - t; 
	}
	else {
		t = 0;
	}
	return t;
};

int CubicBsplines::setA(std::vector<double> _A) {
	if(__A.size() != 0) {
		__A.clear();
	}
	for(int i = 0; i != __N; i++) {
		__A.push_back(_A[i]);
	}
	return 0;
};

int CubicBsplines::set(const ScalarFunction& _f1, const ScalarFunction& _f2, double _x1, double _x2) {
	__N = _x2 - _x1 + 3;
	int n = _x2 - _x1 + 1;
	__delta = 1 - _x1;
	std::vector<double> A;
	double M[n*n]={0};
	double B[n]={0};
	for(int i = 0; i != n; i++) {
		if(i == 0) {
			M[0] = 4;
			M[n] = 2;
			B[0] = 6 * _f1(_x1) + 2 * _f2(_x1);
		} 
		else if(i == n - 1) {
			M[n * n - 1] = 4;
			M[n * (n-1) - 1] = 2;
			B[n - 1] = 6 * _f1(_x2) - 2 * _f2(_x2);
		}
		else {
			M[i * n + i] = 4;
			M[(i+1) * n + i] = 1;
			M[(i-1) * n + i] = 1;
			B[i] = 6 * _f1(_x1 + i); 
		}
	}
	int ipiv[n];
	LAPACKE_dgesv(LAPACK_COL_MAJOR, n, 1, M, n, ipiv, B, n);
	A.push_back(B[1] - 2 * _f2(_x1));
	for(int i = 0; i != n; i++) {
		A.push_back(B[i]);
	}
	A.push_back(B[n - 2] + 2 * _f2(_x2));
	setA(A);
	return 0;
};

double CubicBsplines::interpolate(double _x) {
	double t = 0;
	for(int i = 0; i != __N; i++) {
		t = t + __A[i]*Bspline(i - 1, _x + __delta);
	}
	return t;
};
