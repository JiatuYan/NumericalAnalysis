#include "PLG.h"

int main(int argc, char* argv[])
{
	Permutation<2,2> B;
	int C[2][3] = {1,2,3,4,5,6};
	memcpy(B.Pm,C,sizeof(C));
	std::cout << C[1][1] << ' ' << B.Pm[1][1] << std::endl;
	for(int i = 0; i != 2; i++) {
		for(int j = 0 ; j != 3; j++) {
			std::cout << B.Pm[i][j] << std::endl;
		}
	}
	Gather o;
	PLG<2, 2> p;
	//o = p.__P;;
	std::vector<std::vector<int> >::iterator r=p.__P.begin();
	//std::cout << p.__P.size();
	//std::vector<int>::iterator r1;
	for(;r!=p.__P.end();r++) {
		for(int i = 0; i != 2; i++)
			std::cout << (*r)[i];
		std::cout << std::endl;
	}
	for(int i = 0; i != 2; i++) {
		for(int j = 0; j != 3; j++) {
			std::cout << i+1 << j << '!' << '!' << std::endl;
			for(r = p.__W[i][j].G.begin(); r != p.__W[i][j].G.end(); r++) {
				for(int i = 0; i != 2; i++)
					std::cout << (*r)[i];
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
