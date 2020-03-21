#include "function1.h"
#include "SecantMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in( "input.txt");
	std::ofstream my_out("output1.txt");
	function1 f;
	SecantMethod S;
	double e, fe;
	int t;
	for(int i=0; i!=10; i++) {
		my_in >> e >> fe >> t;
		S.set(e, fe, t);
		my_out << std::fixed << std::setprecision(15) << S.solve(f, 0, M_PI_2) << "\t" << S.num() << std::endl;
	}
	my_in.close();
	my_out.close();
	return 0;
}
