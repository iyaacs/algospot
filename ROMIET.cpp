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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 1987654321;
using namespace std;
inline double distto(pair<double,double> & lhs, pair<double,double> & rhs){
	return sqrt(((lhs.first - rhs.first)*(lhs.first - rhs.first)) + ((lhs.second - rhs.second)*(lhs.second - rhs.second)));
}
inline double segdist(pair<double,double> & A, pair<double,double> & B, pair<double,double> & P){
	double linelen = distto(A, B);
	if (linelen == 0){ return distto(A, P); }
	double prj = ((P.first - A.first)*(B.first - A.first) + (P.second - A.second)*(B.second - A.second))/linelen;
	if (prj < 0){ return distto(A, P); }
	else if (prj > linelen){ return distto(B, P); }
	else{
		return fabs((-1)*(P.first-A.first)*(B.second-A.second)+(P.second-A.second)*(B.first-A.first)) / linelen;
	}
}
void solve(vector<vector<pair<double,double> > >& island){
	int a = 0;
	int b = 0;
	double dist = INF;
	for (int i = 0; i < island.size(); i++){
		for (int j = i + 1; j < island.size(); j++){
			for (int k = 0; k < island[i].size(); k++){
				for (int l = 0; l < island[j].size(); l++){
					pair<double,double>  A = island[i][k];
					pair<double,double>  B = island[i][(k + 1)%island[i].size()];
					pair<double,double>  C = island[j][l];
					pair<double,double>  D = island[j][(l + 1) % island[j].size()];
					if (dist > segdist(A, B, C)){ dist = segdist(A, B, C); a = i + 1; b = j + 1; }
					if (dist > segdist(A, B, D)){ dist = segdist(A, B, D); a = i + 1; b = j + 1; }
					if (dist > segdist(C, D, A)){ dist = segdist(C,D,A); a = i + 1; b = j + 1; }
					if (dist > segdist(C, D, B)){ dist = segdist(C,D,B); a = i + 1; b = j + 1; }
				}
			}
		}
	}
	printf("%d %d\n%.2lf\n", a, b, dist);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		vector<vector<pair<double,double> > > island;
		for (int i = 0; i < N; i++){
			int M;
			scanf("%d", &M);
			vector<pair<double,double> > points;
			for (int j = 0; j < M; j++){
				double x, y;
				scanf("%lf%lf", &x, &y);
				points.push_back(make_pair(x, y));
			}
			island.push_back(points);
		}
		solve(island);
	}
}