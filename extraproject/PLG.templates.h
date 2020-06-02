#include "PLG.h"

template <int D, int _n>
Permutation<D, _n>& Permutation<D, _n>::operator=(const Permutation& A) {
	if(this == &A) {
		return *this;
	}
	for(int i = 0; i != D; i++) {
		for(int j = 0; j != _n+1; j++) {
			this->Pm[i][j] = A.Pm[i][j];
		}
	}
	this->t = A.t;
	return *this;
}

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
};

template<int D, int _n>
int PLG<D, _n>::BackTrackPLG(Gather _k, std::vector<int> _q) {
	__U.clear();
	Permutation<D, _n> A = root();
	BackTrack(_k, _q, A);
	return 0;
}

template<int D, int _n>
Permutation<D, _n> PLG<D, _n>::root() {
	Permutation<D, _n> A;
	A.t = 0;
	for(int i = 0; i != D; i++) {
		for(int j = 0; j != _n + 1; j++) {
			A.Pm[i][j] = -1;
		}
	}
	return A;
};
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
		if(StopAfterAccept()) {
			return 0;
		}
	}
	else if(Reject(_k, _q, _A)) {
		return 0;
	}
	Permutation<D, _n> S;
	S = first(_k, _q, _A);
	while(S.t != - 1) {
		BackTrack(_k, _q, S);
		S = next(_k, _q, _A, S);
		std::cout << S.t << std::endl;
	}
};

template <int D, int _n>
bool PLG<D, _n>::Accept(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	if(_A.t < D*(_n + 1)) {
		return false;
	}	
	else if(Deter(_k, _q, _A)) {
		std::cout << "Accept" << std::endl;
		return true;
	}
	else {
		return false;
	}
};

template <int D, int _n>
bool PLG<D, _n>::Deter(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	Gather PW, PP;
	PW = Permute(_A, __W[D - 1][_n]);
	PP = Permute(_A, __P);
	int hw[int(pow(_n + 1, D+1) + 1)] = {0};
	int hp[int(pow(_n + 1, D+1) + 1)] = {0};
	int hash;
	int pol = 0;
	std::vector<std::vector<int> >::iterator itr;
	std::vector<int>::iterator it;
	for(itr = _k.begin(); itr != _k.G.end(); itr++) {
		hash = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			hash = hash*(_n + 1) + (*it);   
		}
		hw[hash]++;
	}
	for(itr = PW.begin(); itr != PW.G.end(); itr++) {
		hash = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			hash = hash*(_n + 1) + (*it); 
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
			hash = hash*(_n + 1) + (*it);   
		}
		hp[hash]++;
	}
	for(it = _q.begin(); it != _q.end(); it++) {
		hash = hash*(_n + 1) + (*it); 
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
	if(_W.G.size() == 0) {
		return B;
	}
	int card,t;
	std::vector<std::vector<int> >::iterator itr;
	std::vector<int>::iterator it;
	for(itr = _W.begin(); itr != _W.G.end(); itr++) {
		card = 0;
		for(it = (*itr).begin(); it != (*itr).end(); it++) {
			if(_A.Pm[card][(*it)] == -1) {
				t = (*it);
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

template <int D, int _n>
int PLG<D, _n>::vs(int _t) {
	return 1 + (_t - 1) % D;
};

template <int D, int _n>
bool PLG<D, _n>::Reject(Gather _k, std::vector<int> _q, Permutation<D, _n> _A) {
	if(_A.t == D*(_n+1)) {
		return !Accept(_k, _q, _A);
	}
	else if(_A.t == 0) {
		return 0;
	} 
	else {
		int l = vs(_A.t);
		int m = (_A.t - l) / D;
		Gather Ap = Permute(_A, __W[l - 1][m]);
		std::vector<std::vector<int> >::iterator itr;
		std::vector<int>::iterator it;
		int k[int(pow(_n + 1, D+1) + 1)] = {0};
		int hash;
		for(itr = _k.begin(); itr != _k.G.end(); itr++) {
			hash = 0;
			for(it = (*itr).begin(); it != (*itr).end(); it++) {
				hash = hash*(_n + 1) + (*it);   
			}
			k[hash]++;
		}
		for(itr = Ap.begin(); itr != Ap.end(); itr++) {
			hash = 0;
			for(it = (*itr).begin(); it != (*itr).end(); it++) {
				hash = hash*(_n + 1) + (*it);
			}
			if(k[hash] == 0) {
				return 1;
			}
		}
	}
	return 0;
};

template <int D, int _n>
Permutation<D, _n> PLG<D, _n>::first(Gather _k, std::vector<int> _q,
									Permutation<D, _n> _A) {
	std::cout << std::endl << "first" << std::endl;
	int l = vs(_A.t + 1);
	std::cout << l;
	int m = (_A.t) / D;
	std::cout << m;
	Permutation<D, _n> B;
	B = _A;
	B.t++;
	int Z[_n + 1]={0};
	for(int i = 0; i != m; i++) {
		if(B.Pm[l - 1][i] != -1) {
			Z[B.Pm[l - 1][i]] ++;
		}
	}
	for (int i = _n; i != - 1; i--) {
		if(Z[i] == 0) {
			B.Pm[l - 1][m] = i;
			break;
		}
	}
	for(int i = 0; i != D; i++)  {
		for(int j = 0;j != _n+1; j++) {
			std::cout << B.Pm[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << B.t << std::endl;
	return B;
};  

template <int D, int _n>
Permutation<D, _n> PLG<D, _n>::next(Gather _k, std::vector<int> _q,
									Permutation<D, _n> _A, Permutation<D, _n> _B) {
	std::cout << std::endl << "next" << std::endl;
	for(int i = 0; i != D; i++)  {
		for(int j = 0;j != _n+1; j++) {
			std::cout << _B.Pm[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << _B.t << std::endl;
	int l = vs(_A.t + 1);
	int m = (_A.t) / D;
	std::cout << l << ' '<< m << std::endl;
	Permutation<D, _n> C = _B;
	int Z[_n + 1] = {0};
	int i;
	for(i = 0; i != m; i++) {
		if(_B.Pm[l - 1][i] != -1) {
			Z[_B.Pm[l - 1][i]] ++;
		}
	}
	for(i = 0; i != _n + 1; i++) {
		if(Z[i] == 0) {
			if(_B.Pm[l - 1][m] == i) {
				C.t = -1;
				std::cout << C.t;
				return C;
			}
			break;
		}
	}
	for(i = _B.Pm[l - 1][m] - 1; i != -1; i--) {
		if(Z[i] == 0) {
			C.Pm[l - 1][m] = i;
			break;
		}
	}
	for(int i = 0; i != D; i++)  {
		for(int j = 0;j != _n+1; j++) {
			std::cout << C.Pm[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << C.t << std::endl;
	return C;
};
