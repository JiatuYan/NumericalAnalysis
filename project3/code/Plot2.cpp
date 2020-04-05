/**
 * @file Plot2.cpp
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-04-04
 */
#include "function2.h"
#include "NewtonFormula.h"

int main(int argc, char *argv[])
{
	double x;
	function2 f;
	NewtonFormula N;
	std::vector<double> A;
	char pointlist[256];
	for(int n = 5; n != 25; n = n + 5) {
		sprintf(pointlist,"Plot2_%d.txt",n);
		std::ofstream my_out(pointlist);
		for(int i = 1; i != n + 1; i++) {
			x = (2*i - 1)*M_PI/(2*n);
			x = std::cos(x);
			A.push_back(x);
		}
		N.set(f,A);
		std::cout << N.pn(A,0) << std::endl;
		for(int k = -10000; k != 10001; k++) {
			x = k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << N.pn(A, x) << std::endl;
		}
		my_out.close();
		A.clear();
	}
	return 0;
}
