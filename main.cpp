#include<bits/stdc++.h>
// #include<atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

// #define MOD 998244353
// const ll MOD = 1000000007;

// const long INF = 1000000000000000000;

// constexpr long long INF = (1LL << 60);
// constexpr int INF = (1 << 30);

// using mint = modint998244353;
// using mint = modint1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// 任意長整数型
// using Bint = mp::cpp_int;
// using Real = mulp::number<mulp::cpp_dec_float<32>>;
// cout  << fixed << setprecision(15);

template<typename T>
void print(vector<T> &V){
	cout << "[";
	for(int i = 0; i < V.size(); i++){
		cout << V[i];
		if(i < V.size() - 1){
			cout << ", ";
		}
	}
	cout << "]";
}

template<typename T>
int deg(vector<T> &X){
	for(int i = X.size()-1; i >= 0; i--){
		if(X[i] != 0){
			return i;
		}
	}
	return -1;
}

// F = Q G + R. (Q, R)
template<typename T>
pair<vector<T>, vector<T>> div(vector<T> R, vector<T> &G){
	// int degF = deg(F);
	int degF = deg(R);
	int degG = deg(G);
	// vector<T> R(degF+1);
	// for(int i = 0; i < degF+1; i++){
	// 	R[i] = F[i];
	// }
	int degQ = max(0, degF - degG);
	// cerr << "degQ: " << degQ << endl;
	vector<T> Q(degQ + 1);
	for(int i = degQ; i >= 0; i--){
		Q[i] = R[degG+i] / G[degG];
		// cerr << R[degG+i] << "/" << G[degG] << " = " << Q[i]<< endl;

		for(int j = 0; j <= degG; j++){
			R[j+i] -= Q[i] * G[j];
		}
		for(int j = 0; j < R.size(); j++){
			// cout << R[j] << ", ";
		}
		// cout << endl;
	}

	pair<vector<T>, vector<T>> res = {Q, R};
	return res;
}

template<typename T>
vector<T> cyclotomicPolynomial(int n){
	static vector<vector<T>> polys = {{0}};
	if(n < polys.size()){
		return polys[n];
	}
	vector<int> F(n+1, 0);
	F[0] = -1;
	F[n] = 1;
	for(int i = 1; i < n; i++){
		if(n % i == 0){
			// vector<T> s = {1, 2, 3};
			vector<T> c = cyclotomicPolynomial<T>(i);
			div(F, c);
			auto [r, s] = div(F, c);
			F = r;
		}
	}
	polys.push_back(F);
	return polys[n];
}

int main(){
	// vector<int> F = {-1, 0, 0, 0, 0, 0, 1};
	// vector<int> G = {1, 1, 1};
	// vector<int> F = {};

	// auto [Q, R] = div(F, G);
	// // for(int i = 0; i < Q.size(); i++){
	// // 	cout << Q[i] << ", ";
	// // }
	// // cout << endl;
	// print(Q);
	for(int i = 0; i <= 105; i++){
		vector<int> P = cyclotomicPolynomial<int>(i);
		cout << i << ": ";
		print(P);
		cout << endl;
	}
    return 0;
}
