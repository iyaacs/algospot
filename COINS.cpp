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
using namespace std;
long long solve(long long pay, vector<long long>& coin, vector<vector<long long> >& cache, long long type){
	if (type == -1){ return 0; }
	if (pay < 0){return 0;}
	long long& ret = cache[pay][type];
	if (ret != -1){ return ret; }
	if (pay == 0){ return ret=1; }
	if (type == 0){
		if (pay%coin[type] == 0){ return ret = 1; }
		return ret = 0;
	}
	ret = 0;
	for (long long sum = 0; sum <= pay; sum += coin[type]){
		ret += solve(pay - sum, coin, cache, type - 1)%MOD;
	}
	return ret;
}

int main(){
ios::sync_with_stdio(false);
long long T;
cin >> T;
while (T--){
	long long pay, n;
	cin >> pay >> n;
	vector<long long> coin;
	vector<vector<long long> >cache;
	for (long long i = 0; i < 5001; i++){
		vector<long long> vbuf;
		for (long long j = 0; j < 101; j++){ vbuf.push_back(-1); }
		cache.push_back(vbuf);
	}
	for (long long i = 0; i < n; i++){
		long long buf;
		cin >> buf;
		coin.push_back(buf);
	}
	for (long long i = 0; i < n; i++){
		coin[i] *= -1;
	}
	sort(coin.begin(), coin.end());
	for (long long i = 0; i < n; i++){
		coin[i] *= -1;
	}

	cout << solve(pay, coin, cache, n - 1)%MOD << endl;
}
system("pause");
}