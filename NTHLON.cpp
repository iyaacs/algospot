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
#include<stack>
#define INF 987654321
using namespace std;
const int V = 402;
vector<int> dijkstra(int src, vector<vector<pair<int, int> > >& adj){
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost){ continue; }
		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextdist = cost + adj[here][i].second;
			if (dist[there]>nextdist){
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}
int solve(vector<int>& A, vector<int>& B, vector<vector<pair<int, int> > >& adj){
	const int START = 401;
	for (int i = 0; i < V; i++){
		adj[i].clear();
	}
	for (int i = 0; i < A.size(); i++){
		int d = A[i] - B[i];
		adj[START].push_back(make_pair(d+200, A[i]));
	}
	for (int d = -200; d <= 200; d++){
		for (int i = 0; i < A.size(); i++){
			int next = d + A[i] - B[i];
			if (abs(next)>200){ continue; }
			adj[d+200].push_back(make_pair(next+200, A[i]));
		}
	}
	vector<int> shortest = dijkstra(START, adj);
	int ret = shortest[200];
	if (ret == INF){ return -1; }
	return ret;
}
int main(){

	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;

		vector<int> A;
		vector<int> B;

		for (int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			A.push_back(a);
			B.push_back(b);
		}

		vector<vector<pair<int, int> > > adj;
		for (int i = 0; i <402; i++){
			vector<pair<int, int> > vpbuf;
			adj.push_back(vpbuf);
		}
		int ret = solve(A, B, adj);
		if (ret == -1){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << ret << endl;
		}
	}
	system("pause");
}