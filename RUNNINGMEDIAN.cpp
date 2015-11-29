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
#define INF 1987654321
#define MOD 20090711
using namespace std;
//A[i] = (A[i-1] * a + b) % 20090711

class gen{
public:
	long long seed, a, b;
	gen(long long _a, long long _b) :a(_a), b(_b), seed(1983){}
	long long next(){
		long long ret = seed;
		seed = (seed*a + b) % 20090711;
		return ret;
	}
};
long long solve(long long n, gen g){
	priority_queue<long long, vector<long long>, less<long long> > maxheap;
	priority_queue<long long, vector<long long>, greater<long long> > minheap;
	long long ret = 0;
	for (long long cnt = 1; cnt <= n; cnt++){
		if (maxheap.size() == minheap.size()){ maxheap.push(g.next()); }
		else{
			minheap.push(g.next());
		}
		if (!minheap.empty() && !maxheap.empty() && minheap.top()<maxheap.top()){
			long long a = maxheap.top();
			long long b = minheap.top();
			maxheap.pop();
			minheap.pop();
			maxheap.push(b);
			minheap.push(a);
		}
		ret = (ret + maxheap.top()) % MOD;
	}
	return ret;
}
int main(){
	long long T;
	cin >> T;
	while (T--){
		long long n, a, b;
		cin >> n >> a >> b;
		gen g(a, b);
		cout << solve(n, g) << endl;
	}
	system("pause");
}