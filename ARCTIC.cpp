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
#define MOD 1000000007
using namespace std;
double getdist(pair<double, double> lhs, pair<double, double> rhs){
	double one = lhs.first - rhs.first;
	double two = lhs.second - rhs.second;
	one = abs(one);
	two = abs(two);
	one *= one;
	two *= two;
	double ret = sqrt(one + two);
	return ret;
}
void dfs(vector<vector<double> >& adj, vector<bool>& visited, double mid, int idx){
	visited[idx] = true;
	for (int i = 0; i < adj.size(); i++){
		if (visited[i] == false && adj[idx][i]<mid){
			dfs(adj, visited, mid, i);
		}
	}
}
bool issolve(vector<vector<double> >& adj, double mid){
	int N = adj.size();
	vector<bool> visited(N, false);
	dfs(adj, visited, mid, 0);
	int ret = 0;
	for (int i = 0; i < N; i++){ ret += visited[i]; }
	if (ret == N){ return true; }
	else{ return false; }
}
double solve(vector<pair<double,double> >& pair){
	double mmin = 0;
	double mmax = INF;
	int N = pair.size();
	vector<vector<double> > adj;
	for (int j = 0; j < N; j++){
		vector<double> vbuf;
		for (int k = 0; k < N; k++){
			vbuf.push_back(getdist(pair[j], pair[k]));
		}
		adj.push_back(vbuf);
	}

	for (int i = 0; i < 200; i++){
		double mid = (mmin + mmax) / 2;
		if (issolve(adj, mid)){
			mmax = mid;
		}
		else{
			mmin = mid;
		}

	}
	return (mmax + mmin) / 2.0;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<pair<double, double> > point;
		for (int i = 0; i < N; i++){
			double x, y;
			cin >> x >> y;
			point.push_back(make_pair(x, y));
		}
		printf("%.2lf\n", solve(point));
	}

	system("pause");
}