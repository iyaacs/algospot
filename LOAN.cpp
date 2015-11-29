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
bool solve1(double N, double M, double P, double C){
	double n = N;
	double m = M;
	double p = P;
	double c = C;
	for (int i = 0; i < m; i++){
		n = n + ((n*(p / 12)) / 100);
		n -= c;
	}

	if (n >= 0){ return false; }
	else{ return true; }

}
double solve2(double N, double M, double P){
	double n = N;
	double m = M;
	double p = P;
	double lo = 0;
	double hi = INF;
	for (int i = 0; i < 300; i++){
		double mid = (lo + hi) / 2;
		if (solve1(N, M, P, mid)){ hi = mid; }
		else{ lo = mid; }
	}
	return (lo + hi) / 2;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		double N, M, P;
		cin >> N >> M >> P;
		printf("%.10lf\n", solve2(N, M, P));
	}
	system("pause");
}