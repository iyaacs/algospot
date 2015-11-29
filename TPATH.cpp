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
void dfs(int lo, int hi, int here, vector<vector<pair<int, int> > >& adj, vector<bool>& visited){
	visited[here] = true;
	if (here == adj.size() - 1){ return; }
	//cout << lo << " " << hi << " " << here << endl;
	for (int i = 0; i < adj[here].size(); i++){
		int next = adj[here][i].first;
		int val = adj[here][i].second;
		if (val<lo || val>hi){ continue; }
		if (!visited[next]){
			dfs(lo, hi, next, adj, visited);
		}
	}
}
bool haspath(int lo, int hi, vector<vector<pair<int, int> > >& adj){
	
	int N = adj.size();
	vector<bool> visited(N, false);
	dfs(lo, hi, 0, adj, visited);
	return visited[N - 1];
}
int solve1(int low, vector<int>& weights, vector<vector<pair<int, int> > >& adj){
	
}
int solve2(vector<int>& weights, vector<vector<pair<int, int> > >& adj){
	int ret = INF;
	for (int i = 0; i < weights.size(); i++)
	{
		ret = min(ret, solve1(i,weights,adj) - weights[i]);
	}
	return ret;
}
int solve3(vector<int>& weights, vector<vector<pair<int,int> > >& adj){
	int lo = 0;
	int hi = 0;
	int ret = INF;
	while (true){
		if (haspath(weights[lo], weights[hi], adj)){
			ret = min(ret, weights[hi] - weights[lo]);
			lo++;
		}
		else{
			if (hi == weights.size() - 1){ break; }
			hi++;
		}
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		vector<vector<pair<int, int> > > adj;
		for (int i = 0; i < N; i++){
			vector<pair<int, int> > vpbuf;
			adj.push_back(vpbuf);
		}
		vector<int> weights;
		for (int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			weights.push_back(c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		sort(weights.begin(), weights.end());
		cout << solve3(weights, adj) << endl;
	}
	system("pause");
}