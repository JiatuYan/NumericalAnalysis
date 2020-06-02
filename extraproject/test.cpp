#include "PLG.h"

int main(int argc, char* argv[])
{
	PLG<2, 2> P;
	Gather k;
	std::vector<int> a = {1,1};
	k.G.push_back(a);
	a[1]=2;
	k.G.push_back(a);
	a[1]=0;
	k.G.push_back(a);
	a[0]=0;
	a[1]=2;
	k.G.push_back(a);
	a[1]=0;
	k.G.push_back(a);
	a[0]=2;
	k.G.push_back(a);
	Permutation<2,2> U;
	Permutation<2,2> A;
	A.Pm[0][0]=1;
	A.Pm[0][1]=0;
	A.Pm[0][2]=2;
	A.Pm[1][0]=0;
	A.Pm[1][1]=2;
	A.Pm[1][2]=1;
	A.t=6;
	std::cout << U.Pm[0][0] << ' ' << U.t << std::endl;
	std::cout << '!' << std::endl;
	Gather W;
	W = P.Permute(A,W);
	if(W.begin() == W.end()) {
		std::cout << "Right" << std::endl;
	}
		P.BackTrackPLG(k,a);
	std::cout << '?' << std::endl;
	U = *P.__U.begin();
	for(int i = 0; i != 2; i++) {
		for(int j = 0; j != 3; j++) {
			std::cout << U.Pm[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
