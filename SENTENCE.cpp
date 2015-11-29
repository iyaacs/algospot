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
#include<iomanip>
#include<tr1/unordered_map>
#define INF 987654321
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;
	string kk;
	getline(cin, kk);
	tr1::unordered_map<string, int> sen;
	for (int i = 0; i < M; i++){
		string buf;
		getline(cin, buf);
		string kk = "";
		for (int i = 0; i < buf.length(); i++){
			kk += buf[i];
			sen[kk] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++){
		string buf;
		getline(cin, buf);
		if (sen[buf] != 0){ sum++; }
	}
	cout << sum << endl;
	system("pause");
}