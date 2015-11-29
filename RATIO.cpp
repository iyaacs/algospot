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
#define INF 2000000001
long long solve1(long long b, long long a){

	return (a * 100) / b;
}
long long solve2(long long N, long long M){
	if (solve1(N, M) == solve1(N + INF, M + INF)){ return -1; }
	long long lo = -1;
	long long hi = INF;
	for (int i = 0; i < 200; i++){
		long long mid = (lo + hi) / 2;
		if (solve1(N, M) == solve1(N + mid, M + mid)){ lo = mid; }
		else{ hi = mid; }
	}
	return hi;
}
int main(){
	long long T;
	cin >> T;
	while (T--){
		double N, M;
		cin >> N >> M;
		cout << solve2(N, M) << endl;


	}
	system("pause");
}