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
#include<stack>
#define mod 1000000007
using namespace std;
long long solve1(long long n) {
    long long ret = n * 2 - 1;
    long long ret2 = ret;
    for (long long mul = 1; mul <= ret2 - 1; mul += 2) {
	   ret *= mul;
	   ret %= mod;
    }
    return ret%mod;
}

int main() {
    while (true) {
	   long long n;
	   cin >> n;
	   if (n == 0) { break; }
	   long long pv = 1;
	   for (int i = 0; i < 2 * n - 1; i++) {
		  pv *= 2;
		  pv %= mod;
	   }
	   pv *= solve1(n);
	   pv %= mod;
	   cout << pv << endl;
    }
    system("pause");
}