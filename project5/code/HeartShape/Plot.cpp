#include "CubicSpline.h"

class functiony1 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		if(x >=0) {
			t = 2.0/3.0*(pow(3.0 - x*x*x*x, 0.5) + x);
		}
		else {
			t = 2.0/3.0*(pow(3.0 - x*x*x*x, 0.5) - x);
		}
	};
};

class functiony2 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		if(x>=0) {
			t = 2.0/3.0*(-pow(3.0 - x*x*x*x, 0.5) + x);
		}
		else {
			t = 2.0/3.0*(-pow(3.0 - x*x*x*x, 0.5) - x);
		}
	};
};

class functionx : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		if(x >= 0) {
			t = x*x;
		}	
		else {
			t = -x*x;
		}
	};
};
int main(int argc, char* argv[])
{
	double m = pow(3.0, 0.25);
	CubicSpline C;
	functiony1 fy1;
	functiony2 fy2;
	functionx fx;
	double x;
	int n;
	std::vector<double> A;
	char pointlist[256];
	int B[3] = {5,20,80};
	for(int i = 0; i!= 3; i++) {
		n=B[i];
		sprintf(pointlist,"Plot1y_%d.txt",n*2);
		std::ofstream my_out(pointlist);
		A.clear();
		for(int j = 0; j!= n; j++) {
			A.push_back(-m + m*2.0*j / (n - 1));
		}
		C.set(fy1, 2.0/3.0, 2.0/3.0, A);
		for(int k = 0; k != 10000.0; k++) {
			x = -m + m*2.0*k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << C.interpolate(fy1, x) << std::endl;
		}
		my_out.close();
	}	
	for(int i = 0; i!= 3; i++) {
		n=B[i];
		sprintf(pointlist,"Plot2y_%d.txt",n*2);
		std::ofstream my_out(pointlist);
		A.clear();
		for(int j = 0; j!= n; j++) {
			A.push_back(-m + m*2.0*j / (n - 1));
		}
		C.set(fy2, 2.0/3.0, 2.0/3.0, A);
		for(int k = 0; k != 10000.0; k++) {
			x = -m + 2.0*m*k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << C.interpolate(fy2, x) << std::endl;
		}
		my_out.close();
	}
	for(int i = 0; i!= 3; i++) {
		n=B[i];
		sprintf(pointlist,"Plotx_%d.txt",n*2);
		std::ofstream my_out(pointlist);
		A.clear();
		for(int j = 0; j!= n*2; j++) {
			A.push_back(-m + m*2.0*j / (n - 1));
		}
		C.set(fx, 2*m, 2*m, A);
		for(int k = 0; k != 10000.0; k++) {
			x = -m + 2.0*m*k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << C.interpolate(fx, x) << std::endl;
		}
		my_out.close();
	}
	return 0;
};                                      
