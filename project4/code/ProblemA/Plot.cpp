/**
 * @file Plot.cpp
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-04-12
 */
#include "function.h"
#include "CubicSpline.h"

int main(int argc, char *argv[])
{
	double x;
	int n;
	function f;
	CubicSpline C;
	std::vector<double> A;
	std::ofstream m_out("maxnorm.txt"); 
	char pointlist[256];
	int B[5] = {6,11,21,41,81};
	for(int i = 0; i!= 5; i++) {
		n=B[i];
		sprintf(pointlist,"Plot_%d.txt",n);
		std::ofstream my_out(pointlist);
		A.clear();
		for(int j = 0; j!= n; j++) {
			A.push_back(-1 + 2.0*j/(n-1.0));
		}
		C.set(f, A);
		m_out << n - 1  << ' ' << std::fixed << std::setprecision(15) <<  C.Max(f) << std::endl;
		for(int k = -1*10000; k != 1*10000; k++) {
			x = k/10000.0;
			my_out << std::fixed << std::setprecision(15) << x << ' ' << C.interpolate(f, x) << std::endl;
		}
		my_out.close();
	}
	m_out.close();
	return 0;
}
