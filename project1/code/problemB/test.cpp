/**
 * @file test.cpp
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "function.h"
#include "NewtonMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in("input.txt");			//input from input.txt
	std::ofstream my_out("output.txt");			//output to output.txt
	function f;
	functiond fd;
	NewtonMethod N;
	double e, x_0;
	int t;
	for(int i=0; i!=20; i++) {					//calculate 10 times with different range of postconditions
		my_in >> e >> t >> x_0;
		N.set(e, t);							//set the postconditions.
		my_out << std::fixed << std::setprecision(15) << N.solve(f, fd, x_0) << "\t" << N.num() << std::endl;
		//output the root and the iterating times. 
	}											
	my_in.close();
	my_out.close();
	return 0;
}
