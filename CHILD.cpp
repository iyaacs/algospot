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

void floyd(vector<vector<vector<int> > >& adj){
	int V = adj.size();
	for (int i = 0; i < V; i++){ adj[i][i][0] = 0; adj[i][i][1] = 0; }
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				adj[i][j][0] = min(adj[i][j][0], adj[i][k][0] + adj[k][j][0]);
			}
		}
	}
}
void floyd(vector<vector<vector<int> > >& adj, vector<vector<int> >& via){
	int V = adj.size();
	for (int i = 0; i < V; i++){ adj[i][i][0] = 0; adj[i][i][1] = 0; }
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				if (adj[i][j][0] > adj[i][k][0] + adj[k][j][0]){
					via[i][j] = k;
					adj[i][j][0] = adj[i][k][0] + adj[k][j][0];
				}
			}
		}
	}
}

void findpath(vector<vector<int> >& via, int u, int v, vector<int>& path){
	if (via[u][v] == -1){
		path.push_back(u);
		if (u != v){ path.push_back(v); }
	}
	else{
		int w = via[u][v];
		findpath(via, u, w, path);
		path.pop_back();
		findpath(via, w, v, path);
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int V, E;
		cin >> V >> E;
		vector<vector<vector<int> > > adj(V, vector<vector<int> >(V, vector<int>(2, INF)));
		for (int i = 0; i < E; i++){
			int src, dst, dist;
			cin >> src >> dst >> dist;
			src--; dst--;
			int mmindist = adj[src][dst][0];
			int mmindist2 = adj[src][dst][1];
			if (dist < mmindist){
				swap(adj[src][dst][0], adj[src][dst][1]);
				swap(adj[dst][src][0], adj[dst][src][1]);
				adj[src][dst][0] = dist;
				adj[dst][src][0] = dist;
				continue;
			}
			if (dist < mmindist2){
				adj[src][dst][1] = dist;
				adj[dst][src][1] = dist;
			}
		}
		vector<vector<vector<int> > > originaladj = adj;
		
		vector<vector<int> > via(V, vector<int>(V, -1));
		vector<int> path;
		floyd(adj, via);
		findpath(via, 1, 0, path);
		int one = adj[1][0][0];
		for (int i = 0; i < path.size() - 1; i++){
			int src = path[i];
			int dst = path[i + 1];
			swap(originaladj[src][dst][1], originaladj[src][dst][0]);
			originaladj[dst][src][0] *= -1;
		}
		
		floyd(originaladj);
		int two = originaladj[1][V - 1][0];
		cout << one + two << endl;

	}

	system("pause");
}