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
int solve1(vector<int>& arr, vector<int>& cache, int idx){
	int& ret = cache[idx];
	if (ret != -1){ return ret; }
	ret = 1;
	for (int i = idx + 1; i < arr.size(); i++){
		if (arr[idx] < arr[i]){ ret = max(ret, solve1(arr, cache, i)+1); }
	}
	return ret;
}
int solve2(vector<int>& arr){
	int ret = 0;
	vector<int> cache(arr.size(), -1);
	for (int i = 0; i < arr.size(); i++){
		ret = max(ret, solve1(arr, cache, i));
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
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}
		cout << solve2(arr) << endl;
	}
	system("pause");
}