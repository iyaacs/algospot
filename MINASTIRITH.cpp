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
#define INF 987654321
using namespace std;
const double pi = 2.0*acos(0);

void convert(vector<double>& Y, vector<double>& X, vector<double>& R, vector<pair<double, double> >& RANGES){
	int n = Y.size();
	for (int i = 0; i < n; i++){
		double loc = fmod(2 * pi + atan2(Y[i], X[i]), 2 * pi);
		double range = 2.0*asin(R[i] / 2.0 / 8.0);
		RANGES.push_back(make_pair(loc-range,loc+range));
	}
	sort(RANGES.begin(), RANGES.end());
}


int solve2(double begin, double end, vector<pair<double, double> >& RANGES){
	int used = 0;
	int idx = 0;
	int n = RANGES.size();
	while (begin < end){
		double maxcover = 0;
		while (idx < n && RANGES[idx].first <= begin){
			maxcover = max(maxcover, RANGES[idx].second);
			idx++;
		}
		if (maxcover <= begin){ return INF; }
		begin = maxcover;
		used++;
	}
	return used;
}


int solve1(vector<pair<double, double> >& RANGES){
	int ret = INF;
	sort(RANGES.begin(), RANGES.end());
	int n = RANGES.size();
	for (int i = 0; i < n; i++){
		if (RANGES[i].first <= 0 || RANGES[i].second >= 2 * pi){
			double begin = fmod(RANGES[i].second, 2 * pi);
			double end = fmod(RANGES[i].first + 2 * pi, 2 * pi);
			int K = 1 + solve2(begin, end, RANGES);
			ret = min(ret, K);
		}
	}
	return ret;
}

int main(){
	int C;
	cin >> C;
	while (C--){
		int N;
		cin >> N;
		vector<double> Y;
		vector<double> X;
		vector<double> R;
		vector<pair<double, double> > RANGES;
		for (int i = 0; i < N; i++){
			double y, x, r;
			cin >> y >> x >> r;
			Y.push_back(y);
			X.push_back(x);
			R.push_back(r);
		}
		convert(Y, X, R, RANGES);
		int ret = solve1(RANGES);
		if (ret == INF){ cout << "IMPOSSIBLE" << endl; }
		else{ cout << ret << endl; }
	}
	system("pause");
}