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
#define INF 987654321
using namespace std;

int main(){
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i <= N; i++){
		for (int j = i; j <= N; j++){ sum += (i + j); }
	}
	cout << sum << endl;
	system("pause");
}