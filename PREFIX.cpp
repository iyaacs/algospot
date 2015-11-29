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
using namespace std;

void solve(vector<string>& str, int idx, vector<int>& best, vector<string>& beststr, vector<int>& stridx){
	if (stridx.size() == 0){ return; }
	int N = stridx.size();
	if (best[idx] < N){
		best[idx] = N;
		beststr[idx] = str[stridx[0]].substr(0, idx);
	}
	char before = '@';
	vector<int> stridx2;
	for (int i = 0; i < N; i++){
		if (idx >= str[stridx[i]].size()){ continue; }
		if (str[stridx[i]][idx] != before){
			solve(str, idx + 1, best, beststr,stridx2);
			before = str[stridx[i]][idx];
			stridx2.clear();
		}
		stridx2.push_back(stridx[i]);
	}
	solve(str, idx + 1, best, beststr,stridx2);
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		vector<string> STR;
		for (int i = 0; i < N; i++){
			string str;
			cin >> str;
			STR.push_back(str);
		}
		vector<int> best;
		vector<string> beststr;
		for (int i = 0; i < M + 1; i++){
			best.push_back(0);
			beststr.push_back("");
		}
		vector<int> stridx;
		for (int i = 0; i < N; i++){
			stridx.push_back(i);
		}
		solve(STR, 0, best, beststr,stridx);
		for (int i = 1; i <= M; i++){
			cout << beststr[i] << endl;
		}
	}
	system("pause");
}