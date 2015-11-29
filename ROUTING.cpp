#include<cstring>
#include<iostream>
#include<iomanip>
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
#define INF 987654321
vector<double> solve(double N, double src, vector<vector<pair<double, double> > >& adj){

	cout.precision(30);
	cout.setf(ios::fixed, ios::floatfield);
	vector<double> dist(N, INF);
	dist[src] = 1;
	priority_queue<pair<double, double> > pq;
	pq.push(make_pair(1, src));
	while (!pq.empty()){
		double cost = -pq.top().first;
		double here = pq.top().second;
		pq.pop();
		if (dist[here] < cost){ continue; }
		for (double i = 0; i < adj[here].size(); i++){
			double there = adj[here][i].first;
			double nextdist = cost + adj[here][i].second;
			//cout << there << " " << cost << " " << adj[here][i].second << endl;
			if (dist[there]>nextdist){
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist,there));
			}
		}
	}
	return dist;
}

int main(){
	cout.precision(30);
	cout.setf(ios::fixed, ios::floatfield);
	ios::sync_with_stdio(false);
	double C;
	cin >> C;
	while (C--){cout.precision(30);
	cout.setf(ios::fixed, ios::floatfield);
		double N;
		double M;
		cin >> N >> M;
		vector<vector<pair<double, double> > > adj;
		for (double i = 0; i < N; i++){
			vector<pair<double, double> > vbuf;
			adj.push_back(vbuf);
		}
		for (double i = 0; i < M; i++){
			double a, b, c;
			cin >> a >> b >> c;
			c = log10(c);
			pair <double,double>pbuf = make_pair(b, c);
			adj[a].push_back(pbuf);
		}

		vector<double> ret = solve(N, 0, adj);
		cout <<  setprecision(10)<<10*pow(10, ret[N - 1])<<endl;
	}
}