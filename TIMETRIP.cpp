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
void makelink(vector<vector<bool> >& link)
{
	int N = link.size();
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				link[i][j] = link[i][j] || (link[i][k] && link[k][j]);
			}
		}
	}

}

int solve(vector<vector<pair<int, int>> >& graph, vector<vector<bool> >& link, int from, int to)
{
	int N = graph.size();
	vector<int> upper(N, INF);
	upper[from] = 0;
	for (int i = 0; i < N - 1; i++){
		for (int here = 0; here < N; here++){
			for (int k = 0; k < graph[here].size(); k++){
				int there = graph[here][k].first;
				int cost = graph[here][k].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
		}
	}

	for (int here = 0; here < N; here++){
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int cost = graph[here][i].second;
			if (upper[here] + cost < upper[there]){
				if (link[from][here] && link[here][to]){ return -INF; }
			}
		}
	}
	return upper[to];
}
int main(){
	int C;
	cin >> C;
	while (C--){
		int V, W;
		cin >> V >> W;
		vector<vector<pair<int, int> > > graph;
		vector<vector<pair<int, int> > > graph2;
		for (int i = 0; i < V; i++){
			vector<pair<int, int> > vpbuf;
			graph.push_back(vpbuf);
			graph2.push_back(vpbuf);
		}
		vector<vector<bool> > link(V,vector<bool>(V,false));
		for (int i = 0; i < W; i++){
			int a, b, d;
			cin >> a >> b >> d;
			graph[a].push_back(make_pair(b, d));
			graph2[a].push_back(make_pair(b,-d));
			link[a][b] = true;
		}
		makelink(link);
		if (link[0][1] == false){ cout << "UNREACHABLE" << endl; continue; }

		int ret = solve(graph, link, 0, 1);
		int ret2 = -solve(graph2, link, 0, 1);
		int flag1 = 0;
		int flag2 = 0;
		if (ret == INF || ret == -INF){ cout << "INFINITY"; flag1 = 1; }
		if (flag1 == 0){ cout << ret; }
		cout << " ";
		if (ret2 == INF || ret2 == -INF){ cout << "INFINITY"; flag2 = 1; }
		if (flag2 == 0){ cout << ret2; }
		cout << endl;

	}
	system("pause");
}