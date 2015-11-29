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
#define INF 1987654321
using namespace std;

double solve(int from, int toall, vector<vector<double> >& graph, vector<vector<double> >& cache){
	double& ret = cache[from][toall];
	if (ret != -1){ return ret; }
	int cnt = 0;
	int idx = 0;
	for (int i = 0; i < 21; i++){
		if (pow(2.0, i) == toall){ cnt = 1; idx = i; break; }
	}
	if (cnt == 1) {
		int to = idx;
		return graph[from][to];
	}
	ret = INF;
	for (int i = 0; i < graph.size(); i++){
		if (!(toall & (1 << i))) continue;
		double v = graph[from][i] + solve(i, (toall & ~(1 << i)),graph,cache);
		ret = min(ret, v);
	}
	return ret;
}
double tsp(int from, int toFlag, vector<vector<double> >& graph, vector<vector<double> >& cache) {
	double &ret = cache[from][toFlag]; 
	if (ret != -1) {
		return ret;
	}
	if (__builtin_popcount(toFlag) == 1) {
		double to = __builtin_ctz(toFlag);
		return graph[from][to];
	}

	ret = INF;
	for (int i = 0; i < graph.size(); i++) {
		if (!(toFlag & (1 << i))) continue;

		double v = graph[from][i] + tsp(i, (toFlag & ~(1 << i)),graph,cache);
		ret = min(ret, v);
	}
	return ret;
}
int main(){
	int C;
	cin >> C;
	while (C--){
		int N;
		scanf("%d", &N);
		int NSIZE = pow(2.0, N);
		vector<vector<double> > cache;
		for (int i = 0; i < N; i++){
			vector<double> vbuf;
			for (int j = 0; j < NSIZE; j++){ vbuf.push_back(-1); }
			cache.push_back(vbuf);
		}
		vector<vector<double> > graph;
		for (int i = 0; i < N; i++){
			vector<double> vbuf;
			for (int j = 0; j < N; j++){
				double buf;
				scanf("%lf", &buf);
				vbuf.push_back(buf);
			}
			graph.push_back(vbuf);
		}
		double ret = INF;
		double toall = (1 << N) - 1;
		for (int i = 0; i < N; i++){
			ret = min(ret, tsp(i, toall, graph, cache));
		}
		printf("%.10f\n", ret);
	}


	system("pause");
}