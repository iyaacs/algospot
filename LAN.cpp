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
double prim(vector<vector<pair<double, double> > >& adj, vector<pair<double, double> >& selected, double N){
	selected.clear();
	vector<bool> added(N, false);
	vector<double> minweight(N, INF);
	vector<double> parent(N, -1);
	double ret = 0;
	minweight[0] = 0;
	parent[0] = 0;
	for (double i = 0; i < N; i++){
		double u = -1;
		for (double v = 0; v < N; v++){
			if (!added[v] && (u == -1 || minweight[u] > minweight[v])){ u = v; }
		}
		if (parent[u] != u){
			selected.push_back(make_pair(parent[u], u));
		}
		ret += minweight[u];
		added[u] = true;
		for (double j = 0; j < adj[u].size(); j++){
			double v = adj[u][j].first;
			double weight = adj[u][j].second;
			if (!added[v] && minweight[v] > weight){
				parent[v] = u;
				minweight[v] = weight;
			}
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	double T;
	cin >> T;
	while (T--){
		double N, M;
		cin >> N >> M;
		vector<double> X;
		vector<double> Y;
		vector<vector<pair<double, double> > >adj;
		for (double i = 0; i < N; i++){
			vector<pair<double, double> > vbuf;
			adj.push_back(vbuf);
		}
		for (double i = 0; i < N; i++){
			double x;
			cin >> x;
			X.push_back(x);
		}
		for (double i = 0; i < N; i++){
			double y;
			cin >> y;
			Y.push_back(y);
		}
		vector<vector<bool> > link;
		for (int i = 0; i < N; i++){
			vector<bool> vbuf;
			for (int j = 0; j < N; j++){ vbuf.push_back(false); }
			link.push_back(vbuf);
		}
		for (double i = 0; i < M; i++){
			double a, b;
			cin >> a >> b;
			link[a][b] = 1;
			link[b][a] = 1;
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (i == j){ continue; }
				int flag = 0;
				if (link[i][j] == 1){ flag = 1; }
				double x1 = X[i];
				double y1 = Y[i];
				double x2 = X[j];
				double y2 = Y[j];
				double dist;
				if (flag == 1){ dist = 0; }
				else{ dist = sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)); }
				adj[i].push_back(make_pair(j, dist));
			}
		}
		vector<pair<double, double> > selected;
		printf("%.10lf\n", prim(adj, selected, N));
	}
	system("pause");
}