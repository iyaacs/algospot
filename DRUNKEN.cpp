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
using namespace std;
#define INF 987654321
void solve(vector<vector<int> >& graph, vector<vector<int> >& graph2, vector<int>& TIME){
	int V = graph.size();
	vector<pair<int, int> > order;
	for (int i = 0; i < V; i++){
		order.push_back(make_pair(TIME[i],i));
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < V; i++){
		graph2[i][i] = 0;
	}
	int ret = INF;
	for (int k = 0; k < V; k++){
		int w = order[k].second;
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				graph[i][j] = min(graph[i][j], graph[i][w] + graph[w][j]);
				graph2[i][j] = min(graph[i][w] + TIME[w] + graph[w][j], graph2[i][j]);
			}
		}
	}
}
int main(){ 
	int V, E;
	cin >> V >> E;
	vector<int> TIME;
	for (int i = 0; i < V; i++){
		int buf;
		cin >> buf;
		TIME.push_back(buf);
	}
	vector<vector<int> > graph;
	for (int i = 0; i < V; i++){
		vector<int> vbuf;
		for (int j = 0; j < V; j++){
			vbuf.push_back(INF);
		}
		graph.push_back(vbuf);
	}
	for (int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	vector<vector<int> > graph2=graph;
	solve(graph, graph2, TIME);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int s, t;
		cin >> s >> t;
		s--; t--;
		cout << graph2[s][t] << endl;
	}
	system("pause");
}