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
using namespace std;

unsigned long long mining(unsigned long long& a, unsigned long long& b, unsigned long long& k, unsigned long long prefix, unsigned long long digit) {
	if (prefix == 0){
		if (a == 0){ return 1; }
		else{ return 0; }
	}
	unsigned long long ret = 0;
	unsigned long long num = 1;
	for (unsigned long long i = digit; i<20; i++){
		unsigned long long start = prefix * num;
		unsigned long long end = start + num;
		if (start >= b) { break; }
		start = max(start, a);
		end = min(end, b);
		if (end > start) {
			ret += (end - start);
		}
		num *= 10;
	}
	return ret;
}

unsigned long long findnextdigit(unsigned long long& a, unsigned long long& b, unsigned long long& k, unsigned long long prefix, unsigned long long digit) {
	for (unsigned long long i = 0; i <= 9; i++){
		unsigned long long ret = mining(a, b, k, prefix * 10 + i, digit);
		if (ret >= k){ return i; }
		else{ k -= ret; }
	}
}

unsigned long long solve(unsigned long long& a, unsigned long long& b, unsigned long long& k, unsigned long long prefix) {
	unsigned long long digit = 1;
	unsigned long long ret = 0;
	do {
		unsigned long long ret2 = findnextdigit(a, b, k, ret, digit);
		digit++;
		ret *= 10;
		ret += ret2;
		if (a <= ret && ret < b){ k--; }
	} while (k > 0);
	return ret;
}


int main() {
	unsigned long long T;
	scanf("%lld", &T);
	while (T--){
		unsigned long long a, b, k;
		scanf("%lld %lld %lld", &a, &b, &k);
		b++; k++;
		printf("%lld\n", solve(a, b, k, 0));
	}
	system("pause");
}