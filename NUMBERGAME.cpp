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
#define MOD 1000000007
#define INF 1987654321
using namespace std;
int solve(vector<int>& arr, int left, int right, vector<vector<int> >& cache){
	//left = start at 0, ++
	// right = start at N-1, --
	if (left > right){ return 0; }
	int& ret = cache[left][right];
	if (ret != -INF){ return ret; }
	ret = max(arr[left] - solve(arr, left + 1, right, cache), arr[right] - solve(arr, left, right - 1, cache));
	if (right - left + 1 >= 2){
		ret = max(ret, -solve(arr, left + 2, right, cache));
		ret = max(ret, -solve(arr, left, right - 2, cache));
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<int> arr;
		vector<vector<int> > cache;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < N; j++){ vbuf.push_back(-INF); }
			cache.push_back(vbuf);
		}
		cout << solve(arr, 0, arr.size() - 1, cache) << endl;
	}
	system("pause");
}