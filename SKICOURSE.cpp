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
#define INF 987654321
using namespace std;

int solve1(vector<vector<pair<int, int> > >& graph, int here, int depth, vector<vector<int> >& cache){
	if (depth == 0){ return 0; }
	int& ret = cache[here][depth];
	if (ret != -INF){ return ret; }
	ret = 0;
	for (int i = 0; i < graph[here].size(); i++){
		int next = graph[here][i].first;
		int fun = graph[here][i].second;
		ret = max(ret, fun + solve1(graph, next, depth - 1, cache));
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, M, S;
		cin >> N >> M >> S;
		vector<vector<int> > cache;
		for (int i = 0; i < N + 1; i++){
			vector<int> vbuf;
			for (int j = 0; j < S + 1; j++){ vbuf.push_back(-INF); }
			cache.push_back(vbuf);
		}

		vector<vector<pair<int, int> > > graph;
		for (int i = 0; i < N; i++){
			vector<pair<int, int> > vbuf;
			graph.push_back(vbuf);
		}
		for (int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			graph[a].push_back(make_pair(b, c));
		}
		int ret = 0;
		for (int i = 0; i < N; i++){
			for (int j = S; j >= 0; j--){
				ret = max(ret, solve1(graph, i, S, cache));
			}
		}
		cout << ret << endl;
	}
	system("pause");
}