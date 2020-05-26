#include "PLG.h"

template <int D, int _n>
PLG<D, _n>::PLG() {
	std::vector<int> A(D);
	setP(A, 0, _n);
	setW();
	__U.clear();
};

template <int D, int _n>
int PLG<D, _n>::setP(std::vector<int>& _A, int _t, int _m) {
	std::vector<int>::iterator itr = _A.begin();
	if(_t != _n) {
		_t++;
		for(int i = 0; i != _m+1; i++) {
			(*(itr + _t - 1)) = i;
			setP(_A, _t, _m-i);
		}
	}
	else {
		__P.G.push_back(_A);
	}
	return 0;
}

template <int D, int _n>
int PLG<D, _n>::setW() {
	std::vector<int> A;
	Gather B;
	Gather Z;
	Z.G.assign(__P.begin(), __P.end());
	int pol;
	int i;
	std::vector<int>::iterator it;
	std::vector<std::vector<int> >::iterator itr;
	for(int l = 1; l != D+1; l++) {
		for(int m = 0; m != _n + 1; m++) {
			B.clean();
			itr = Z.G.begin();
			for(;itr != Z.G.end(); itr++) {
				pol = 0;
				i = 1;
				for(it = (*itr).begin(); it != (*itr).end(); it++) {
					if(i < l) {
						if((*it) > m) {
							pol = 1;
							break;
						}
					}
					else if(i == l) {
						if((*it) != m) {
							pol = 1;
							break;
						}
					}
					else {
						if((*it) >= m) {
							pol = 1;
							break;
						}
					}
					i++;
				}
				if(pol == 0) {
					A.assign((*itr).begin(), (*itr).end());
					B.G.push_back(A);
					itr = Z.G.erase(itr);
					itr--;
				}
			}
			__W[l - 1][m] = B;
		}
	}
	return 0;
};

template <int D, int _n>
int PLG<D, _n>::BackTrack(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	if(Accept(_k, _q, _A)) {
		__U.push_back(_A);
		if(stopAfterAccept(_k, _q, _A)) {
			return 0;
		}
	}
	else if(reject(_k, _q, _A)) {
		return 0;
	}
	Permutation<D, _n> S;
	S = first(_k, _q, _A);
	while(S != NULL) {
		BackTrack(_k, _q, S);
		S = next(_k, _q, _A, S);
	}
};

template <int D, int _n>
bool PLG<D, _n>::Accept(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	if(_A.t < D*(_n + 1)) {
		return false;
	}	
	else if(Deter(_k, _q, _A)) {
		return true;
	}
	else {
		return false;
	}
};

template <int D, int _n>
bool PLG<D, _n>::Deter(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	Gather PW, PP;
	PW = permute(_A, __W[D - 1][_n]);
	PP = permute(_A, __P);
	int hw[int(pow(_n, D+1) + 1)];
	int hp[int(pow(_n, D+1) + 1)];
	int hash;
	int pol = 0;
	std::vector<std::vector<int> >::iterator itr;
	std::vector<int>::iterator it;
	for(itr = PW.begin(); itr != PW.G.end(); itr++) {
		hash = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			hash = hash*_n +(*it);   
		}
		hw[hash]++;
	}
	for(itr = __W[D - 1][_n].begin(); itr != __W[D - 1][_n].G.end(); itr++) {
		hash = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			hash = hash*_n + (*it); 
		}
		if(hw[hash] == 0) {
			pol = 1;
			break;
		}
	}
	if(pol == 1) {
		return false;
	}
	for(itr = PP.begin(); itr != PP.G.end(); itr++) {
		hash = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			hash = hash*_n +(*it);   
		}
		hp[hash]++;
	}
	for(it = _q.begin(); it != _q.end(); it++) {
		hash = hash*_n + (*it); 
	}
	if(hp[hash] == 0) {
		pol = 1;
	}
	if(pol == 1) {
		return false;
	}
	else {
		return true;
	}
};

template<int D, int _n>
Gather PLG<D, _n>::Permute(Permutation<D, _n> _A, Gather _W) {
	std::vector<int> A;
	Gather B;
	int card,t;
	std::vector<std::vector<int> >::iterator itr;
	std::vector<int>::iterator it;
	for(itr = _W.begin(); itr != _W.G.end(); itr++) {
		card = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			if(_A.Pm[card][(*it)] = -1) {
				t == (*it);
			}
			else {
				t = _A.Pm[card][(*it)];
			}
			card++;
			A.push_back(t);
		}
		B.G.push_back(A);
		A.clear();
	}
	return B;
};

template <int D, int _n>
bool PLG<D, _n>::StopAfterAccept() {
	return true;
};

