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
int main(){
	long long T;
	cin >> T;
	vector<long long> cache;
	cache.push_back(1);
	cache.push_back(1);
	cache.push_back(5);
	cache.push_back(11);
	for (long long i = 4; i <= 1000; i++){
		long long val = cache[i - 1] + 5 * cache[i - 2] + cache[i - 3] - cache[i - 4];
		cache.push_back(val);
	}
	for(int i=1; i<=T;i++){
		int n;
		cin >> n;
		cout << i<<" "<<cache[n] << endl;
	}
	system("pause");
}