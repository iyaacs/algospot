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
#define INF 9876543210
using namespace std;
bool issolve(vector<double>& beeds, double C, double N, double x){
	double ret = 0;
	for (double i = 0; i < beeds.size(); i++){
		ret += min(beeds[i], x);
	}
	if (ret >= (N*x)){ return true; }
	return false;
}
double solve(vector<double>& beeds, double C, double N){
	double mmin = 0;
	double mmax = INF;
	for (double i = 0; i < 200; i++){
		double mid = (mmin + mmax) / 2.0;
		if (!issolve(beeds, C,N,mid)){ mmax = mid; }
		else{ mmin = mid; }
	}
	return (mmax + mmin) / 2.0;
}

int main(){
	double T;
	cin >> T;
	while (T--){
		double N, C;
		cin >> N >> C;
		vector<double> beeds;
		for (double i = 0; i < C; i++){
			double buf;
			cin >> buf;
			beeds.push_back(buf);
		}
		int pv = solve(beeds, C,N);
		cout << pv << endl;
	}
	system("pause");
}