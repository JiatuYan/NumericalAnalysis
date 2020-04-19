#include "QuadraticBsplines.h"
#include "CubicBsplines.h"

class function1 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = 1/(1+x*x);
		return t;
	};
};

class function2 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = (-2*x)/(1+x*x)/(1+x*x);
		return t;
	};
};

int main(int argc, char* argv[])
{
	double x;
	QuadraticBsplines Q;
	CubicBsplines C;
	function1 f1;
	function2 f2;
	double x1,x2;
	std::ofstream qm_out("Quadratic.txt");
	std::ofstream cm_out("Cubic.txt");
	C.set(f1, f2, -5, 5);
	Q.set(f1, -5, 5);
	for(int k = -5*10000; k != 5*10000 + 1; k++) {
		x = k/10000.0;
		qm_out << std::fixed << std::setprecision(15) << x << ' ' << Q.interpolate(x) << std::endl;
		cm_out << std::fixed << std::setprecision(15) << x << ' ' << C.interpolate(x) << std::endl;
	}
	qm_out.close();
	cm_out.close();
	std::ofstream qe_t("ErrortestQ.txt");
	std::ofstream ce_t("ErrortestC.txt");
	double A[7] = {-3.5, -3, -0.5, 0, 0.5, 3, 3.5};
	for(int i = 0 ; i!= 7; i++) {
		qe_t << std::fixed << std::setprecision(15) << A[i] << ' ' << fabs(Q.interpolate(A[i]) - f1(A[i])) << std::endl;
		ce_t << std::fixed << std::setprecision(15) << A[i] << ' ' << fabs(C.interpolate(A[i]) - f1(A[i])) << std::endl;
	}
	qe_t.close();
	ce_t.close();
	return 0;
};
