#include "../include/ScalarFunction.h"

class function1 : public ScalarFunction {
public:
	double operator()(double x) const{
		double t = 0;
		t = x*x*x*x*x*x*x*x- 8.0*x*x*x*x*x*x*x + 28.0*x*x*x*x*x*x
			- 56.0*x*x*x*x*x + 70.0*x*x*x*x - 56.0*x*x*x + 28.0*x*x - 8.0*x + 1.0;
		return t;
	};	
};

class function2 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t;
		t = x - 8.0;
		t = t*x + 28.0;
		t = t*x - 56.0;
		t = t*x + 70.0;
		t = t*x - 56.0;
		t = t*x + 28.0;
		t = t*x - 8.0;
		t = t*x + 1.0;
		return t;
	};
};

class function3 : public ScalarFunction {
public:
	double operator()(double x) const {
		double t = 1;
		for(int i = 0; i != 8; i++) {
			t = t*(x - 1.0);
		}
		return t;
	};
};

int main(int argc, char *argv[])
{
	double x;
	double t = 10000000000000000;
	function1 f1;
	function2 f2;
	function3 f3;
	std::ofstream my_out1("./result/function1.txt");
	std::ofstream my_out2("./result/function2.txt");
	std::ofstream my_out3("./result/function3.txt");
	std::ofstream m_out1("./result/magnified_function1.txt");
	std::ofstream m_out2("./result/magnified_function2.txt");
	std::ofstream m_out3("./result/magnified_function3.txt");
	for(int i = 0; i != 101; i++) {
		x = 0.99 + i*0.0002;
		my_out1 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  f1(x) << std::endl;
		my_out2 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  f2(x) << std::endl;
		my_out3 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  f3(x) << std::endl;
		m_out1 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  t*f1(x) << std::endl;
		m_out2 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  t*f2(x) << std::endl;
		m_out3 << std::fixed << std::setprecision(4) << x <<  std::fixed << std::setprecision(16) << ' ' <<  t*f3(x) << std::endl;}
	my_out1.close();
	my_out2.close();
	my_out3.close();
	m_out1.close();
	m_out2.close();
	m_out3.close();
	return 0;
}
