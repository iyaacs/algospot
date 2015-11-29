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
#define MOD 10000000
using namespace std;
long long poly(vector<vector<long long>>& cache, long long n, long long first)
{
	if (n == first) return 1;
	long long& ret = cache[n][first];
	if (ret != -1) return ret;

	ret = 0;
	for (long long second = 1; second <= n - first; ++second) {
		long long add = second + first - 1;
		add *= poly(cache,n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}
long long solve(vector<vector<long long>>& cache, long long x, long long y){


	if (x == y){ return 1; }
	long long& ret = cache[x][y];
	if (ret != -1){ return ret; }
	ret = 0;
	long long front = x - y;
	for (long long i = 1; i <= front; i++){
		for (long long j = y; j <= front; j++){
			ret += solve(cache, front, i);
		}
	}
	return ret; 
}
int main(){
	std::ios::sync_with_stdio(false);
	long long T;
	cin >> T;
	while (T--){
		vector<vector<long long>> cache;
		for (long long i = 0; i < 101; i++){
			vector<long long> vbuf;
			for (long long j = 0; j < 101; j++){
				vbuf.push_back(-1);
			}
			cache.push_back(vbuf);
		}
		long long n;
		cin >> n;
		long long sum = 0;
		for (long long i = 1; i < n; i++){
			//sum += (solve(cache, n, i));
			sum += poly(cache, n, i);
		}
		sum++;
		//sum = sum%MOD;
		cout << sum%MOD << endl;
	}
	system("pause");
}