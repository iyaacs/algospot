#define _CRT_SECURE_NO_WARNINGS
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
#include<iomanip>
#include<limits>
using namespace std;
#define INF 987654321
bool solve1(int K,int dist, vector<int>& L, vector<int>& M, vector<int>& G){
	int sum = 0;
	int n = L.size();
	for (int i = 0; i < n; i++){
		if (dist >= L[i] - M[i]){
			sum += ((min(dist,L[i])-(L[i]-M[i]))/G[i])+1;
		}
	}
	if (sum >= K){ return true; }
	else { return false; }
}
int solve2(int K,vector<int>& L, vector<int>& M, vector<int>& G){
	int lo = -1;
	int hi = 10000000;
	for (int i = 0; i < 100; i++){
		int mid = (lo + hi) / 2;
		if (solve1(K, mid, L, M, G)){ hi = mid; }
		else{ lo = mid; }
	}
	return hi;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<int> L, M, G;
		for (int i = 0; i < N; i++){
			int l, m, g;
			cin >> l >> m >> g;
			L.push_back(l);
			M.push_back(m);
			G.push_back(g);
		}
		cout << solve2(K, L, M, G) << endl;
	}

	system("pause");
}	