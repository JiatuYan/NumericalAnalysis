#include "PLG.h"

int main(int argc, char* argv[])
{
	Gather C;
	Permutation<2,2> B;
	int D[2][3] = {1,0,-1,0,-1,-1};
	memcpy(B.Pm,D,sizeof(D));
	std::cout << D[1][1] << ' ' << B.Pm[1][1] << std::endl;
	for(int i = 0; i != 2; i++) {
		for(int j = 0 ; j != 3; j++) {
			std::cout << B.Pm[i][j] << std::endl;
		}
	}
	Gather o;
	PLG<2, 2> p;
	std::cout << '*' << '*' << std::endl;
	B = p.root();
	for(int i = 0; i != 2; i++) {
		for(int j = 0; j != 3; j++) {
			std::cout << B.Pm[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << B.t << std::endl;
	std::cout << '!' << '?' << std::endl;
	C = p.Permute(B, p.__W[0][1]);
	std::vector<std::vector<int> >::iterator ir = C.begin();
	for(; ir!= C.G.end(); ir++) {
		std::cout << (*ir)[0] << (*ir)[1] << std::endl;
	}
	std::cout << '!' << '?' << std::endl;
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
