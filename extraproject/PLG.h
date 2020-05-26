#ifndef __PAISLEYPARK__PLG__
#define __PAISLEYPARK__PLG__

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

class Gather {
public:	
	std::vector<std::vector<int> > G;
	
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
		int (*Pm)[_n+1] = new int[D][_n+1];
		t = 0;
	};
	int Pm[D][_n+1];
	int t;
};

template <int D, int _n>
class PLG {
public:
	PLG();

	int setP(std::vector<int>& _A, int _t, int _m);

	int setW();

	int BackTrack(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);
	
	bool Accept(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);

	bool Deter(Gather _k, std::vector<int> _q, Permutation<D, _n> _A);
	
	Gather Permute(Permutation<D, _n> _A, Gather _W);

	bool StopAfterAccept();
//private:
	std::vector<Permutation<D, _n> > __U;
	Gather __P;
	Gather __W[D][_n+1];
};
#else
//Do nothing
#endif
