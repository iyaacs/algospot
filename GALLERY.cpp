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
const int DIRECTWATCH = 2;
const int INDIRECTWATCH = 1;
const int NOWATCH = 0;
int dfs(vector<vector<int> >& adj, vector<bool>& visited, int here, int& ret){
	visited[here] = true;
	vector<int> child(3, 0);
	for (int i = 0; i < adj[here].size(); i++){
		int there = adj[here][i];
		if (!visited[there]){
			child[dfs(adj,visited,there,ret)]++;
		}
	}
	if (child[NOWATCH]){
		ret++;
		return DIRECTWATCH;
	}
	if (child[DIRECTWATCH]){
		return INDIRECTWATCH;
	}
	return NOWATCH;
}
int solve(vector<vector<int> >& adj){
	int ret = 0;
	int V = adj.size();
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++){
		if (!visited[i] && dfs(adj, visited, i, ret) == NOWATCH){ ret++; }
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int V, E;
		cin >> V >> E;
		vector<vector<int> > adj;
		for (int i = 0; i < V; i++){
			vector<int> vbuf;
			adj.push_back(vbuf);
		}
		for (int i = 0; i < E; i++){
			int src, dst;
			cin >> src >> dst;
			adj[src].push_back(dst);
			adj[dst].push_back(src);
		}
		cout << solve(adj) << endl;
	}
	system("pause"); 
}