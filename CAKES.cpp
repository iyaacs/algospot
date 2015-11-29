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
using namespace std;

int solve(vector<int>& time){
	int N = time.size();
	int ssum = 0;
	for (int i = 0; i < N; i++){ ssum += time[i]; }
	vector<vector<int> > used(ssum + 1, vector<int> (ssum + 1));
	used[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = ssum; j >= 0; j--) {
			for (int k = ssum; k >= 0; k--) {
				if (used[j][k]) {
					used[j + time[i]][k] = 1;
					used[j][k + time[i]] = 1;
				}
			}
		}
	}

	int best = ssum;
	for (int j = 0; j <= ssum; j++) {
		for (int k = 0; k <= ssum; k++) {
			if (used[j][k]) {
				int total_time = max(ssum - j - k, max(j, k));
				if (total_time < best) best = total_time;
			}
		}
	}

	return best;
}
int main(){
	while (true){
		int N;
		cin >> N;
		if (N == 0){ break; }
		vector<int> time;
		for (int i = 0; i < N; i++){
			int t;
			cin >> t;
			time.push_back(t);
		}
		cout << solve(time) << endl;
	}
}