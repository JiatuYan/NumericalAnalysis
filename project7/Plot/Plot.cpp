/**
 * @file plot.cpp
 * @brief Get the points of condf and condA
 * @author XDDD
 * @version 
 * @date 2020-05-24
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <limits>

class Condf {
public:
	double operator()(double x) const {
		if(x == 0) {
			return 1;
		}
		else {
			return x / (exp(x) - 1);
		}
	};
};

class CondA {
public:
	double operator()(double x)  const {
		if(x == 0) {
			std::cerr << "Undefined" << std::endl;
			std::exit(-1);
		}
		else {
			return exp(x) / x;
		}
	};
};

int main(int argc, char *argv[])
{
	Condf f;
	CondA A;
	double x = 0;
	std::ofstream m_outf("fpoints.txt");
	std::ofstream m_outA("Apoints.txt");
	for(int i = 0; i != 10000; i++) {
		x = x + 1.0/10000;
		m_outf << std::fixed << std::setprecision(15) << x << ' ' << f(x) << std::endl;
		m_outA << std::fixed << std::setprecision(15) << x << ' ' << A(x) << std::endl;
	}
	m_outf.close();
	m_outA.close();
	return 0;
};
