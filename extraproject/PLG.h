#ifndef __PAISLEYPARK__PLG__
#define __PAISLEYPARK__PLG__

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

class Gather {
public:	
	std::vector<std::vector<int> > G;
	
	Gather& operator=(const Gather& _G) {
		if(this == &_G) {
			return *this;
		}
		this->G = _G.G;
		return *this;
	};
	std::vector<std::vector<int> >::iterator begin() {
		return G.begin();
	}

	int size() {
		return G.size();
	}
	std::vector<std::vector<int> >::iterator end() {
		return G.end();
	}
	int clean() {
		G.clear();
		return 0;
	};
};

template <int D, int _n>
class Permutation {
public:
	Permutation<D, _n>() {
		t = 0;
		for(int i = 0; i != D; i++) {
			for(int j = 0; j != _n+1; j++) {
				Pm[i][j] = -1;
			}
		}
	};
	
	Permutation<D, _n>& operator=(const Permutation<D, _n>& A);
	int Pm[D][_n+1];
	int t;
};

template <int D, int _n>
class PLG {
public:
	PLG();

	int setP(std::vector<int>& _A, int _t, int _m);

	int setW();

	int BackTrackPLG(Gather _k, std::vector<int> _q);

	Permutation<D, _n> root();

	int BackTrack(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);
	
	bool Accept(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);

	bool Deter(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);
	
	Gather Permute(Permutation<D, _n> _A, Gather _W);

	bool StopAfterAccept();

	bool Reject(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);
	
	int vs(int _t);
	
	Permutation<D, _n> first(Gather _k, std::vector<int> _q, Permutation<D, _n> _A); 

	Permutation<D, _n> next(Gather _k, std::vector<int> _q, Permutation<D, _n> _A, Permutation<D, _n> _B);
//private:
	std::vector<Permutation<D, _n> > __U;
	Gather __P;
	Gather __W[D][_n+1];
};
#else
//Do nothing
#endif
