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
#define INF 1987654321
using namespace std;
double solve(
	vector<vector<bool> >& city,
	vector< vector <vector <double> > >& cache,
	int from,
	double to,
	double day)
{
	if (day == 0){
		if (to == from){ return 1.0; }
		else{
			return 0.0;
		}
	}
	double& ret = cache[from][to][day];
	if (ret > -0.5){
		return ret;
	}

	ret = 0.0;
	vector<double> tocity;
	for (int i = 0; i < city[from].size(); i++){
		if (city[from][i] == 1){ tocity.push_back(i); }
	}

	for (int i = 0; i < tocity.size(); i++){
		ret += ((solve(city, cache, tocity[i], to, day - 1)) / tocity.size());
	}
	return ret;
}
int main(){
	int C;
	scanf("%d", &C);
	while (C--){
		int N, X, M, T;
		scanf("%d%d%d%d", &N, &X, &M, &T);
		if (X > 26){ X = 26; }
		vector<int> Ai;
		vector<int> Bi;
		for (int i = 0; i < N; i++){
			int buf;
			scanf("%d", &buf);
			buf--;
			Ai.push_back(buf);
		}
		for (int i = 0; i < M; i++){
			int buf;
			scanf("%d", &buf);
			buf--;
			Bi.push_back(buf);
		}
		vector<vector<bool> > connected(N, vector<bool>(N, 0));
		for (int i = 0; i < N; i++){
			int num1 = Ai[i];
			for (int j = -T; j <= T; j++){
				int num2 = num1 + j+N;
				num2 %= N;
				connected[i][num2] = 1;
			}
		}
		for (int i = 0; i < N; i++){
			connected[0][i] = 0;
		}
		connected[0][Ai[0]] = 1;
		vector<vector<vector<double> > > cache;
		for (int i = 0; i < N+1; i++){
			vector<vector<double> > vvbuf;
			for (int j = 0; j < N+1; j++){
				vector<double> vbuf;
				for (int k = 0; k < X+1; k++){
					vbuf.push_back(-1);
				}
				vvbuf.push_back(vbuf);
			}
			cache.push_back(vvbuf);
		}
		for (int i = 0; i < M; i++){
			printf("%.5lf ", solve(connected, cache, 0, Bi[i], X));
		}
		printf("\n");
	}
	system("pause");
}