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
#define DEPTH 9
double dp(vector<vector<map<int, double > > >& cache,vector<vector<double> >& dist, int here, int visited){
	int n = dist.size();
	if (visited == (1 << n) - 1){ return 0; }
	int remain = n - __builtin_popcount(visited);
	double& ret = cache[here][remain][visited];
	if (ret > 0){ return ret; }
	ret = INF;
	for (int next = 0; next < n; next++){
		if (visited&(1 << next)){ continue; }
		ret = min(ret, dp(cache, dist, next, visited + (1 << next))+dist[here][next]);
	}
	return ret;
}
double huri(int visited, vector<double>& minedge, int n){
	double ret = 0;
	for (int i = 0; i < n; i++){
		if (!visited&(1 << i)){ ret += minedge[i]; }
		//if (!visited[i]){ ret += minedge[i]; }
	}
	return ret;
}
void solve1(vector<vector<double> >& dist, vector<int>& path, int visited, double currentlength, double& best, double start, vector<double>& minedge,vector<vector<map<int,double> > >& cache){
	int n = dist.size();
	int here = path.back();
	//cout << visited << endl;
	if (best <= currentlength + huri(visited, minedge,n)){ return; }
	if (path.size() == n){
		best = min(best, currentlength);
		return;
	}
	if (path.size() + DEPTH >= n){
		best = min(best, currentlength + dp(cache, dist, path.back(),visited));
	}
	else{
	for (int next = 0; next < n; next++){
		//if (visited[next]){ continue; }
		if (visited&(1 << next)){ continue; }
		path.push_back(next);
		//visited[next] = true;
		visited |= (1 << next);
		solve1(dist, path, visited, currentlength+dist[here][next], best,start,minedge,cache);
		//visited[next] = false;
		visited &= ~(1 << next);
		//visited -= (1 << next);
		path.pop_back();
	}}
}
double solve2(vector<vector<double> >& dist, double& best, int start,vector<vector<map<int, double> > >& cache){
	int n = dist.size();

	vector<double> minedge;
	for (int i = 0; i < n; i++){
		minedge.push_back(INF);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i != j){ minedge[i] = min(minedge[i], dist[i][j]); }
		}
	}

	for (int i = 0; i < 22; i++){
		for (int j = 0; j <= DEPTH; j++){
			cache[i][j].clear();
		}
	}
	//vector<bool> visited(n, false);
	vector<int> path(1, start);
	//visited[start] = true;
	int visited = 0;
	visited |= (1 << start);
	solve1(dist, path, visited, 0, best,start,minedge,cache);
	return best;
}
int main(){
	int T;
	cin >> T;
	while (T--){

		int N;
		cin >> N;
		vector<vector<double> > dist;
		vector<double> minedge;
		vector<vector<map<int, double > > > cache;

		for (int i = 0; i < 22; i++){
			vector<map<int, double> > vmbuf;
			for (int j = 0; j <= DEPTH; j++){
				map<int, double> mbuf;
				vmbuf.push_back(mbuf);
			}
			cache.push_back(vmbuf);
		}
		for (int i = 0; i < N; i++){
			vector<double> vbuf;
			for (int j = 0; j < N; j++){
				vbuf.push_back(-1);
			}
			dist.push_back(vbuf);
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				double buf;
				cin >> buf;
				dist[i][j] = buf;
			}
		}
		double best=INF;
		for (int i = 0; i < N; i++){
			solve2(dist, best, i,cache);
		}
		printf("%.10f\n",best);
	}

	system("pause"); 
}