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
vector<int> X, Y, R;
int N;
int dist(int a, int b){
	int one = (Y[a] - Y[b])*(Y[a] - Y[b]);
	int two = (X[a] - X[b])*(X[a] - X[b]);
	return one + two;
}
bool enclose(int a, int b){
	if (R[a] > R[b]){
		if (dist(a, b) < ((R[a] - R[b]) * (R[a] - R[b]))){ return true; }
	}
	return false;
}
bool ischild(int parent, int child){
	if (!enclose(parent, child)){ return false; }
	for (int i = 0; i < N; i++){
		if (i == parent){ continue; }
		if (i == child){ continue; }
		if (enclose(parent, i) && enclose(i, child)){ return false; }
	}
	return true;
}
void makegraph(vector<vector<int> >& adj){
	for (int i = 0; i < N; i++){ adj[i][i] = 0; }
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (ischild(i, j)){ adj[i][j] = 1; adj[j][i] = 1; }
		}
	}
}
void floyd(vector<vector<int> >& adj){
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (adj[i][j] > adj[i][k] + adj[k][j]){ adj[i][j] = adj[i][k] + adj[k][j]; }
			}
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		X.clear(); Y.clear(); R.clear();
		cin >> N;
		for (int i = 0; i < N; i++){
			int x, y, r;
			cin >> x >> y >> r;
			X.push_back(x);
			Y.push_back(y);
			R.push_back(r);
		}
		vector<vector<int> > adj(N,vector<int>(N, INF));
		makegraph(adj);
		floyd(adj);
		int mmax = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				mmax = max(mmax, adj[i][j]);
			}
		}
		cout << mmax << endl;

	}
	system("pause");
}