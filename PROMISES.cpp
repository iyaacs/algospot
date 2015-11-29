#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
void floyd(vector<vector<int> >&graph){
	int N = graph.size();
	for (int i = 0; i < N; i++){ graph[i][i] = 0; }
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

}

bool floyd2(vector<vector<int> >&graph, int a, int b, int c){
	if (graph[a][b] <= c){return false; }
	int N = graph.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			graph[i][j] = min(graph[i][j], min(graph[i][a] + c + graph[b][j], graph[i][b] + c + graph[a][j]));
		}
	}
	return true;
}

int main(){
	int C;
	cin >> C;
	while (C--){
		int V, M, N;
		cin >> V >> M >> N;
		vector<vector<int> > graph;
		for (int i = 0; i < V; i++){
			vector<int> vbuf;
			for (int j = 0; j < V; j++){
				vbuf.push_back(INF);
			}
			graph.push_back(vbuf);
		}
		for (int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			graph[a][b] = c;
			graph[b][a] = c;
		}
		floyd(graph);
		int ret = 0;
		for (int i = 0; i < N; i++){
			int a, b, c;
			cin >> a >> b >> c;
			if (!floyd2(graph, a, b, c)){ ret++; }

		}
		cout << ret << endl;
	}

	system("pause");

}