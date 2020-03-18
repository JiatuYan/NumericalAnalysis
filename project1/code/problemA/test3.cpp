#include "function3.h"
#include "BinaryMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in("input.txt");
	std::ofstream my_out("output3.txt");
	function3 f;
	BinaryMethod B;
	double e,fe;
	int t;
	for(int i=0; i!=10; i++) {
		my_in >> e >> fe >> t;
		B.set_error(e, fe, t);
		my_out << std::fixed << std::setprecision(15) << B.solve(f, 1, 3) << "\t" << B.num() << std::endl;
	}
	my_in.close();
	my_out.close();
	return 0;
}
