#include "QuadraticBsplines.h"

double QuadraticBsplines::Bspline(int i, double x) {
	double t;
	if(i - 1 < x && x <= i) {
		t = x - i + 1.0;
		t = t * t / 2.0;
	}
	else if(i < x && x <= i + 1) {
		t = x - i - 0.5;
		t = 0.75 - t * t;
	}
	else if(i + 1 < x && x <= i + 2) {
		t = i + 2.0 - x;
		t = t * t / 2.0;
	}
	else {
		t = 0;
	}
	return t;
};

int QuadraticBsplines::setA(std::vector<double> _A) {
	if(__A.size() != 0) {
		__A.clear();
	}
	for(int i = 0; i != __N; i++) {
		__A.push_back(_A[i]);
	}
	return 0;
};

int QuadraticBsplines::set(const ScalarFunction& _f, double _x1, double _x2) {
	__N = _x2 - _x1 + 2;
	int n = _x2 - _x1;
	__delta = 1 - _x1;
	std::vector<double> A;
	double M[n*n]={0};
	double B[n]={0};
	for(int i = 0; i != n; i++) {
		if(i == 0) {
			M[0] = 5;
			M[1] = 1;
			B[0] = 8 * _f(_x1 + 0.5) - 2 * _f(_x1);
		} 
		else if(i == n - 1) {
			M[n * n - 1] = 5;
			M[n * n - 2] = 1;
			B[n - 1] = 8 * _f(_x2 - 0.5) - 2 * _f(_x2);
		}
		else {
			M[i * n + i] = 6;
			M[i * n + i - 1] = 1;
			M[i * n + i + 1] = 1;
			B[i] = 8 * _f(_x1 + i + 0.5);
		}
	}
	int ipiv[n];
	LAPACKE_dgesv(LAPACK_COL_MAJOR, n, 1, M, n, ipiv, B, n);
	A.push_back(2*_f(_x1) - B[0]);
	for(int i = 0; i != n; i++) {
		A.push_back(B[i]);
	}
	A.push_back(2*_f(_x2) - B[n - 1]);
	setA(A);
	return 0;
};

double QuadraticBsplines::interpolate(double _x) {
	double t = 0;
	for(int i = 0; i != __N; i++) {
		t = t + __A[i] * (Bspline(i , _x + __delta));
	}
	return t;
}
