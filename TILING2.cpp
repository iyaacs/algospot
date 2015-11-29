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
unsigned long long solve(vector<unsigned long long>& cache, unsigned long long n){
	//1000000007
	unsigned long long & ret = cache[n];
	if (ret != -1){ return ret; }
	if (n == 0){ return 0; }
	if (n == 1){ return 1; }
	if (n == 2){ return 2; }
	ret = 0;
	ret = (solve(cache, n - 1) % 1000000007 + solve(cache, n - 2) % 1000000007) % 1000000007;
	return ret;
}
int main(){
	std::ios::sync_with_stdio(false);
	unsigned long long T;
	cin >> T;
	while (T--){
		unsigned long long buf;
		cin >> buf;
		vector<unsigned long long> cache;
		for (unsigned long long i = 0; i < 101; i++){
			cache.push_back(-1);
		}
		cout << solve(cache,buf) << endl;
	}
	system("pause");
}