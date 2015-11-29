#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
int solve1(const string& a, const string& b){
	string bb = b + b;
	int one = bb.find(a);
	return one;
}
int solve2(const string& a, const string& b){
	string aa = a + a;
	int one = aa.find(b);
	return one;
}

int main(){
	double C;
	cin >> C;
	while (C--){
		int N;
		cin >> N;
		vector<string> strarr;
		for (int i = 0; i <= N; i++){
			string str;
			cin >> str;
			strarr.push_back(str);
		}
		int ret = 0;
		for (int i = 0; i < N; i++){
			if (i % 2 == 0){ ret += solve1(strarr[i], strarr[i + 1]); }
			else{ ret += solve2(strarr[i], strarr[i + 1]); }
		}
		cout << ret << endl;
	}
	system("pause");
}