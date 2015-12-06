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
#define INF 9876543210
using namespace std;
int V;
int N;
int M;
vector<vector<int> > capacity;
vector<vector<int> > flow;
vector<int> win;
vector<pair<int, int> > match;
int cache;
void init(){
	cache = 0;
	V = 0;
	N = 0;
	M = 0;
	win.clear();
	match.clear();
	capacity.clear();
	flow.clear();
}
void init2(){
	V = 0;
	capacity.clear();
	flow.clear();
}
int networkflow(int src, int sink){
	flow.clear();
	for (int i = 0; i < V; i++){
		vector<int> vbuf(V, 0);
		flow.push_back(vbuf);
	}
	int totalflow = 0;	
	while (true){
		vector<int> parent(V, -1);
		queue<int> q;
		parent[src] = src;
		q.push(src);
		while (!q.empty() && parent[sink] == -1){
			int here = q.front();
			q.pop();
			for (int there = 0; there < V; there++){
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
					q.push(there);
					parent[there] = here;
				}
			}
		}

		if (parent[sink] == -1){ break; }
		int amount = INF;
		for (int p = sink; p != src; p = parent[p]){
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		}
		for (int p = sink; p != src; p = parent[p]){
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalflow += amount;
	}
	return totalflow;
}

bool issolve(int totalwin){

	for (int i = 1; i < N; i++){
		if (win[i] >= totalwin){ return false; }
	}
	V = M + N + 2;
	capacity.clear();
	for (int i = 0; i < V; i++){
		vector<int> vbuf(V, 0);
		capacity.push_back(vbuf);
	}
	for (int i = 0; i < M; i++){
		capacity[0][2 + i] = 1;
		capacity[2 + i][2 + M + match[i].first] = 1;
		capacity[2 + i][2 + M + match[i].second] = 1;
	}
	for (int i = 0; i < N; i++){
		int maxwin;
		if (i == 0){ maxwin = totalwin; }
		else{ maxwin = totalwin - 1; }
		capacity[2 + M + i][1] = (maxwin-win[i]);
	}
	
	return (networkflow(0, 1) == M && capacity[2+M][1]==flow[2+M][1]);
}
int solve(){
	int lo = -1;
	int hi = cache+1;
	while (lo + 1 < hi){
		int mid = (lo + hi) / 2;
		if (issolve(mid)){ hi = mid; }
		else{ lo = mid; }
	}

	if (hi >= cache+1){ return -1; }
	return hi;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		init();
		cin >> N >> M;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			win.push_back(buf);
		}
		cache = win[0];
		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			if (a == 0 || b == 0){ cache++; }
			match.push_back(make_pair(a, b));
		}
		cout << solve() << endl;
	}
	system("pause");
}