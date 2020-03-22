/**
 * @file test2.cpp
 * @brief 
 * @author XDDD
 * @version 
 * @date 2020-03-20
 */
#include "function2.h"
#include "SecantMethod.h"

int main(int argc, char *argv[])
{
	std::ifstream my_in( "input.txt");				//input from input.txt
	std::ofstream my_out("output2.txt");			//output to output2.txt
	function2 f;
	SecantMethod S;
	double e, fe;
	int t;
	for(int i=0; i!=10; i++) {						//calculate 10 times with different range of postconditions.
		my_in >> e >> fe >> t;
		S.set(e, fe, t);							//set the postconditions.
		my_out << std::fixed << std::setprecision(15) << S.solve(f, 1, 1.4) << "\t" << S.num() << std::endl;
		//output the root and the iterating times.
	}
	my_in.close();
	my_out.close();
	return 0;
}
