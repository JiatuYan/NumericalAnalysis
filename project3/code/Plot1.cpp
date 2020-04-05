/**
 * @file Plot1.cpp
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-04-04
 */
#include "function1.h"
#include "NewtonFormula.h"

int main(int argc, char *argv[])
{
	double x;
	function1 f;
	NewtonFormula N;
	std::vector<double> A;
	char pointlist[256];
	for(int n = 2; n != 10; n = n+2) {
		sprintf(pointlist,"Plot1_%d.txt",n);
		std::ofstream my_out(pointlist);
		for(int i = 0; i != n + 1; i++) {
			x = -5 + 10.0*i/n;
			A.push_back(x);
		}
		N.set(f,A);
		std::cout << N.pn(A,0) << std::endl;
		for(int k = -5*10000; k != 5*10000; k++) {
			x = k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << N.pn(A, x) << std::endl;
		}
		my_out.close();
		A.clear();
	}
	return 0;
}
