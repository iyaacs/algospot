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
void printpick(vector<double>& road,vector<double>& picked){
	int n = picked.size();
	for (int i = 0; i < n; i++){
		cout << road[picked[i]] << " ";
	}
	cout << endl;
}
void pick(int n, vector<double>& road, vector<double>& picked, int topick){
	if (topick == 0){ printpick(road,picked); return; }
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++){
		picked.push_back(next);
		pick(n, road,picked, topick - 1);
		picked.pop_back();
	}
}
bool solve(vector<double>& road, int n, double gap){
	double limit = 0;
	int set = 0;
	for (int i = 0; i < road.size(); i++){
		if (limit <= road[i]){
			set++;
			limit = road[i] + gap;
		}
	}
	if (n <= set){ return true; }
	else{ return false; }

}

double solve2(vector<double>& road, int n){
	double low = 0;
	double high = 300;
	for (int i = 0; i < 100; i++){
		double mid = (low + high) / 2.0;
		if (solve(road, n, mid)){ low = mid; }
		else{ high = mid; }
	}
	return (low + high) / 2;
}
int main(){
	int C;
	cin >> C;
	while (C--){
		int N, M;
		cin >> N >> M;
		vector<double> road;
		for (int i = 0; i < M; i++){
			double buf;
			cin >> buf;
			road.push_back(buf);
		}
		//vector<double> picked;
		//pick(M, road,picked, N);
		printf("%.2f\n", solve2(road, N));

	}
	system("pause");
}	