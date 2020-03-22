/**
 * @file test1.cpp
 * @brief 
 * @author XDDD 
 * @version 
 * @date 2020-03-20
 */
#include "function1.h"
#include "BinaryMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in("input.txt");			//input from input.txt
	std::ofstream my_out("output1.txt");		//output to output1.txt
	function1 f;
	BinaryMethod B;
	double e,fe;
	int t;
	for(int i=0; i!=10; i++) {					//calculate 10 times with different range of postconditions
		my_in >> e >> fe >> t;					
		B.set_error(e, fe, t);					//set the postcondition
		my_out << std::fixed << std::setprecision(15) << B.solve(f, 0, M_PI_2) << "\t" << B.num() << std::endl;
		//output the root and the iterating times
	}
	my_in.close();
	my_out.close();
	return 0;
}
