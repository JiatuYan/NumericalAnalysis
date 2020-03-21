#include "function2.h"
#include "SecantMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in( "input.txt");
	std::ofstream my_out("output2.txt");
	function2 f;
	SecantMethod S;
	double e, fe;
	int t;
	std::cout << 1.4 - f(1)*(1.4 - 1)/(f(1.4) - f(1));
	for(int i=0; i!=10; i++) {
		my_in >> e >> fe >> t;
		S.set(e, fe, t);
		my_out << std::fixed << std::setprecision(15) << S.solve(f, 1, 1.4) << "\t" << S.num() << std::endl;
	}
	my_in.close();
	my_out.close();
	return 0;
}
