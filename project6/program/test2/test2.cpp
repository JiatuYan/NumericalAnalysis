#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

int main(int argc, char* argv[])
{
	std::ofstream my_out("./result/FL.txt");
	double UFL, OFL; 
	UFL = 1.0/2;
	OFL = 2.0*(2.0 - 1.0/4);
	my_out << UFL << ' ' << OFL << std::endl;
	my_out.close();
	std::ofstream nor_out("./result/NormalizedN.txt");
	double  t = UFL;
	double m = 1.0;
	for(int i = 0; i != 1 - (-1) + 1; i ++) {
		while(m != 2) {
			nor_out << m*t << std::endl;
			nor_out << -m*t << std::endl;
			m = m + 1.0/4;
		} 
		t = t * 2.0;
		m = 1;
	}
	nor_out.close();
	std::ofstream sub_out("./result/SubnormalN.txt");
	t = UFL;
	m = 1.0/4;
	while(m != 1) {
		sub_out << m*t << std::endl;
		sub_out << -m*t << std::endl;
		m = m + 1.0/4;
	}
	sub_out.close();
	return 0;
}
