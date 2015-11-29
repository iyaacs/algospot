#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cassert>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<deque>
using namespace std;
const int MOD=20090711;

int countsym(int N, int K, vector<vector<int> >& symcache){
	if (N == K || N == K * 2){ return 1; }
	int& ret = symcache[N][K];
	if (ret != -1){ return ret; }
	ret = 0;
	int limit = (N - (K << 1));
	for (int i = 1; i <= limit; i++){
		int m = (K + i - 1)*countsym(limit, i, symcache) % MOD;
		ret += m;
		ret %= MOD;
	}
	return ret;
	return 0;
}

int countpoly(int N, int K,vector<vector<int> >& cache) {
	if (N == K) return 1;
	int &ret = cache[N][K];
	if (ret != 0) return ret;

	int limit = N - K;
	for (int line2 = 1; line2 <= limit; line2++) {
		int m = (K + line2 - 1) * countpoly(limit, line2,cache) % MOD;
		ret += m;
		ret %= MOD;
	}
	return ret;
	return 0;
}

int main() {
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		int ret1 = 0;
		int ret2 = 0;
		vector<vector<int> > cache(N+10, vector<int>(N+1, 0));
		vector<vector<int> > cache2(N+10, vector<int>(N+1, -1));
		for (int i = 1; i < N; i++){
			int m = countpoly(N, i, cache)%MOD;
			ret1 += m;
			ret1 %= MOD;
			int s = countsym(N, i, cache2)%MOD;
			ret2 += s;
			ret2 %= MOD;
		}
		cout << (ret1 - ret2 + MOD) % MOD << endl;
	}

	

	system("pause");
}