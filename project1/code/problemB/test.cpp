#include "function.h"
#include "NewtonMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in("input.txt");
	std::ofstream my_out("output.txt");
	function f;
	functiond fd;
	NewtonMethod N;
	double e, x_0;
	int t;
	for(int i=0; i!=20; i++) {
		my_in >> e >> t >> x_0;
		N.set(e, t);
		my_out << std::fixed << std::setprecision(15) << N.solve(f, fd, x_0) << "\t" << N.num() << std::endl;
	}
	my_in.close();
	my_out.close();
	return 0;
}
