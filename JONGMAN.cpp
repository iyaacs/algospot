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
#define INF 1987654321
using namespace std;
void solve(vector<vector<int> >& adj, vector<int>& routecost, vector<int>& routecost2, int now, int cost, map<int,int>& step){
	if (now == 1){
		if (step[2] == 1){
			routecost[1] = cost;
		}
		return;
	}
	for (int i = 1; i < adj.size(); i++){
		if (step[i] == 0 && adj[now][i]!=0){
			int nextcost = cost + adj[now][i];
			if (step[2] == 1){
				if (routecost[i]>nextcost){
					step[i] = 1;
					routecost[i] = nextcost;
					solve(adj, routecost,routecost2, i, nextcost, step);
					step[i] = 0;
				}
			}
			else if (routecost2[i] > nextcost){
				step[i] = 1;
				routecost2[i] = nextcost;
				solve(adj, routecost, routecost2, i, nextcost, step);
				step[i] = 0;
			}
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		vector<vector<int> > adj;
		vector<int> routecost1;
		vector<int> routecost2;
		for (int i = 0; i < N; i++){
			routecost1.push_back(INF);
			routecost2.push_back(INF);
		}
		map<int, int> step;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < N; j++){
				vbuf.push_back(0);
			}
			adj.push_back(vbuf);
		}

		for (int i = 0; i < M; i++){
			int a, b, c;
			cin >> a >> b >> c;
			adj[a][b] = c;
			adj[b][a] = c;
		}
		solve(adj, routecost1, routecost2, 0, 0, step);
		cout << routecost1[1] << endl;

	}
	system("pause");
}