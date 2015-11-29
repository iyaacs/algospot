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
unsigned long long solve(vector<unsigned long long>& cache, unsigned long long n){
unsigned long long & ret = cache[n];
if (ret != -1){ return ret; }
if (n == 0){ return 0; }
if (n == 1){ return 1; }
if (n == 2){ return 2; }
ret = 0;
ret = (solve(cache, n - 1) % MOD + solve(cache, n - 2) % MOD) % MOD;
return ret;
}
int main(){
std::ios::sync_with_stdio(false);
unsigned long long T;
cin >> T;
while (T--){
unsigned long long n;
cin >> n;
vector<unsigned long long> cache;
for (unsigned long long i = 0; i < 101; i++){
cache.push_back(-1);
}
if (n == 0) { cout << 0 << endl; continue; }
if (n == 1) { cout << 0 << endl; continue; }
if (n == 2) { cout << 0 << endl; continue; }

if (n % 2 == 0) //even
{
	unsigned long long ans = solve(cache, n);
	ans = (ans - solve(cache, n / 2) + MOD) % MOD;
	ans = (ans - solve(cache, n / 2-1) + MOD) % MOD;
	cout << ans;
}
else //odd
{
	cout << (solve(cache, n) - solve(cache, n / 2)+MOD)%MOD;
}
cout << endl;
}
system("pause");
}
