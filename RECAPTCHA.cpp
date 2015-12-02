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
void floyd(vector<vector<pair<double, string> > >& adj){
	int N = adj.size();
	for (int i = 0; i < N; i++){
		adj[i][i].first = -1.0;
	}
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = i+1; j < N; j++){
				if (adj[i][k].first == -1.0){ continue; }
				if (adj[k][j].first == -1.0){ continue; }
				if (adj[i][j].first < adj[i][k].first*adj[k][j].first){
					adj[i][j].first = adj[i][k].first*adj[k][j].first;
					adj[i][j].second = adj[i][k].second + adj[k][j].second;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<vector<pair<double, string> > > adj;
		for (int i = 0; i < N; i++){
			vector<pair<double, string> > vpbuf;
			for (int j = 0; j < N; j++){
				pair<double, string> pbuf;
				pbuf.first = -1.0;
				pbuf.second = "";
				vpbuf.push_back(pbuf);
			}
			adj.push_back(vpbuf);
		}
		for (int i = 0; i < N; i++){
			for (int j = i + 1; j < N; j++){
				double mmax = 0.0;
				string c2 = "";
				for (char k = 'a'; k <= 'z'; k++){
					double d;
					cin >> d;
					if (d > mmax){ mmax = d; c2 = k; }
				}
				adj[i][j].first = mmax;
				adj[i][j].second = c2;
			}
		}
		floyd(adj);	
		cout << adj[0][N-1].second << endl;

	}

	system("pause");
}