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
#include<hash_map>
#define INF 1987654321
#define MOD 1000000007
using namespace std;
bool solve1(vector<double>& R, vector<double>& C, int K, double cumulativeRank){
	int N = R.size();
	vector<double> vbuf;
	for (int i = 0; i < N; i++){
		vbuf.push_back(cumulativeRank*C[i]-R[i]);
	}
	sort(vbuf.begin(), vbuf.end());
	double ssum = 0;
	for (int i = N - K; i < N; i++){
		ssum += vbuf[i];
	}
	if (ssum >= 0){ return true; }
	else{ return false; }

}
double solve2(vector<double>& R, vector<double>& C, int K){
	double lo = -1;
	double hi = INF;
	for (int i = 0; i < 200; i++){
		double mid = (lo + hi) / 2;
		bool value = solve1(R, C, K, mid);
		if (value){ hi = mid; }
		else{ lo = mid; }
	}
	return (lo + hi) / 2;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<double> R;
		vector<double> C;
		for (int i = 0; i < N; i++){
			int r, c;
			cin >> r >> c;
			R.push_back(r);
			C.push_back(c);
		}
		//cout << solve2(R, C, K) << endl;
		printf("%.10lf\n", solve2(R, C, K));
	}
	system("pause");
}