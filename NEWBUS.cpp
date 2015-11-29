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
void floyd(vector<vector<int> >& adj, vector<vector<int> >& via){
	int V = adj.size();
	for (int i = 0; i < V; i++){
		adj[i][i] = 0;
	}
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				if (adj[i][j] > adj[i][k] + adj[k][j]){
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}
void route(int u, int v, vector<int>& path, vector<vector<int> >& via){
	if (via[u][v] == -1){
		path.push_back(u);
		if (u != v){ path.push_back(v); }
	}
	else{
		int w = via[u][v];
		route(u, w, path,via);
		path.pop_back();
		route(w, v, path, via);
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M, Q;
		cin >> N >> M >> Q;
		vector<vector<int> > adj;
		for (int i = 0; i < N; i++){
			vector<int> vbuf(N, INF);
			adj.push_back(vbuf);
		}
		for (int i = 0; i < M; i++){
			int v, u, d;
			cin >> v >> u >> d;
			v--; u--;
			adj[v][u] = d;
			adj[u][v] = d;
		}

		for (int i = 0; i < Q; i++){
			int v, u;
			cin >> v >> u;
			v--; u--;

			vector<vector<int> > adj2 = adj;
			vector<vector<int> > via;

			for (int j = 0; j < N; j++){
				vector<int> vbuf(N, -1);
				via.push_back(vbuf);
			}
			floyd(adj2,via);
			int mmin = adj2[v][u];
			if (mmin == INF){ cout << "no" << endl; continue; }

			vector<int> path;
			route(u, v, path, via);
			int count = 1;
			for (int j = 0; j < path.size()-1; j++){
				int src = path[j];
				int dst = path[j + 1];
				vector<vector<int> > adj3 = adj;
				adj3[src][dst] = INF;
				adj3[dst][src] = INF;
				vector<vector<int> > via2;
				for (int k = 0; k < N; k++){
					vector<int> vbuf(N, -1);
					via2.push_back(vbuf);
				}
				floyd(adj3, via2);
				if (mmin == adj3[u][v]){ count++; break; }
			}
			if (count == 1){ cout << "only" << endl; }
			else{ cout << "many" << endl; }
		}
	}

	system("pause");
}