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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 1987654321
using namespace std;


bool solve(int n){
	bool ret = true;
	vector<bool> cache(10, false);
	cache[n % 10] = true;
	while (true){
		if ((n / 10) == 0){break; }
		n /= 10;
		if (cache[n % 10]){ ret = false; break; }
		else{ cache[n % 10] = true; }
	}
	return ret;
}


int main()
{
	vector<int> cache(1000010, -1);
	int cnt = 0;
	int i = 0;
	while (true){
		if (cnt >= 1000010){ break; }
		if (solve(i)){ cache[cnt] = i; cnt++; }
		i++;
	}
	while (true){
		int N;
		cin >> N;
		if (N == 0){ break; }
		cout << cache[N] << endl;
	}
	system("pause");
}