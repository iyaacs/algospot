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
map<vector<int>, int> cache;
void init(){
	for (int N = 1; N <= 8; N++){
		vector<int> arr;
		for (int i = 0; i < N; i++){ arr.push_back(i); }
		queue<vector<int> > q;
		q.push(arr);
		cache[arr] = 0;
		while (!q.empty()){
			vector<int> here = q.front();
			q.pop();
			int cost = cache[here];
			for (int i = 0; i < N; i++){
				for (int j = i+2; j <= N; j++){
					vector<int> vbuf = here;
					reverse(vbuf.begin() + i, vbuf.begin() + j);
					if (cache.count(vbuf) == 0){ cache[vbuf] = cost + 1; q.push(vbuf); }
				}
			}
		}
	}
}

int solve(vector<int>& arr){
	vector<int> sorted = arr;
	sort(sorted.begin(), sorted.end());
	int N = arr.size();
	vector<int> id(N, -1);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (sorted[i] == arr[j]){ id[i] = j; }
		}
	}
	return cache[id];
}

int main(){
	init();
	int T;
	cin >> T;

	while (T--){
		int N;
		cin >> N;
		vector<int> arr;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}
		cout << solve(arr) << endl;
	}
	system("pause");
}