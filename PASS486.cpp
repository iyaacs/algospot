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
#define INF 1987654321
#define END 10000000
int cache[END];
int main(){
	int T;
	cin >> T;
	for (int i = 1; i < END; i++){
		for (int j = i; j < END; j+=i){
			cache[j]++;
		}
	}
	while (T--){
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int ret = 0;
		for (int i = lo; i <= hi; i++){
			if (cache[i] == n){ ret++; }
		}
		cout << ret << endl;
	}
}