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
#define INF 987654321987654321
using namespace std;

vector<long long> solve(long long N, long long src, vector<vector<pair<long long, long long> > >& graph){
	vector<long long> dist(N, INF);
	dist[src] = 0;
	priority_queue<pair<long long, long long> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()){
		long long cost = -pq.top().first;
		long long here = pq.top().second;
		pq.pop();
		if (dist[here] < cost){ continue; }
		for (double i = 0; i < graph[here].size(); i++){
			double there = graph[here][i].first;
			double nextdist = cost + graph[here][i].second;
			if (dist[there]>nextdist){
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}

int main(){
	ios::sync_with_stdio(false);
	long long C;
	cin >> C;
	while (C--){
		long long N, M;
		cin >> N >> M;
		vector<vector<pair<long long, long long> > > graph;
		map<long long, map<long long, long long> > mg;
		vector<long long> A;
		vector<long long> B;
		vector<long long> C;
		for (long long i = 0; i < N; i++){
			vector<pair<long long, long long> > vbuf;
			graph.push_back(vbuf);
		}
		for (long long i = 0; i < M; i++){
			long long a, b, c;
			cin >> a >> b >> c;
			A.push_back(a);
			B.push_back(b);
			C.push_back(c);
			mg[a][b] = c;
			mg[b][a] = c;
		}

		for (long long i = 0; i < M; i++){
			long long a, b, c;
			a = A[i];
			b = B[i];
			c = C[i];
			if (mg[a][b] >= c){ mg[a][b] = c; }
			pair<long long, long long> pbuf = make_pair(b, mg[a][b]);
			pair<long long, long long> pbuf2 = make_pair(a, mg[b][a]);
			graph[a].push_back(pbuf);
			graph[b].push_back(pbuf2);
		}
		vector<long long> retbuf = solve(N, 0, graph);
		cout << retbuf[N - 1] << endl;
	}
	system("pause");
}