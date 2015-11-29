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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 1987654321
using namespace std;
void solve(vector<vector<int> >& board){
	int N = board.size();
	for (int i = 0; i < N; i++){
		board[i][i] = 0;
	}
	for (int i = 0; i < N; i++){
		for (int k = 0; k < N; k++){
			for (int j = 0; j < N; j++){
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}
}
vector<int> solve2(int src, vector<vector<pair<int, int> > >& board){
	int V = board.size();
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost){ continue; }
		for (int i = 0; i < board[here].size(); i++){
			int there = board[here][i].first;
			int nextdist = board[here][i].second + cost;
			if (dist[there]>nextdist){
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist, there));
			}
		}
	}
	return dist;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int V, E, N, M;
		cin >> V >> E >> N >> M;
		vector< vector<pair<int, int> > > board;
		for (int i = 0; i < V+1; i++){
			vector<pair<int,int > > vbuf;
			board.push_back(vbuf);
		}
		for (int i = 0; i < E; i++){
			int a, b, t;
			cin >> a >> b >> t;
			a--; b--;
			board[a].push_back(make_pair(b, t));
			board[b].push_back(make_pair(a, t));
		}
		vector<int> fire;
		vector<int> center;
		for (int i = 0; i < N; i++){
			int buf; cin >> buf; buf--; fire.push_back(buf);
		}
		for (int i = 0; i < M; i++){
			int buf; cin >> buf; buf--; center.push_back(buf);
			board[V].push_back(make_pair(buf, 0));
			board[buf].push_back(make_pair(V, 0));
		}
		vector<int> ret = solve2(V, board);
		int pv = 0;
		for (int i = 0; i < N; i++){
			pv += ret[fire[i]];
		}
		cout << pv << endl;
	}
	system("pause");
}