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
#define INF 987654321
using namespace std;

int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<pair<int, int> > chart;
		for (int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			chart.push_back(make_pair(a, b));
		}
		if (N == 1){ cout << chart[0].second - chart[0].first << endl; continue; }
		int ret = -INF;
		for (int i = 0; i < N; i++){
			int leftdown = chart[i].first;
			int leftup = chart[i].second;
			int lo = -INF;
			int hi = INF;
			for (int j = i; j < N; j++){
				int rightdown = chart[j].first;
				int rightup = chart[j].second;
				lo = max(lo, rightdown);
				hi = min(hi, rightup);
				if (lo >= leftup || hi <= leftdown){ break; }
				int up = min(leftup, hi);
				int down = max(leftdown, lo);
				ret = max((up - down)*(j - i + 1),ret);
			}
		}
		cout << ret << endl;
	}
	system("pause");
}