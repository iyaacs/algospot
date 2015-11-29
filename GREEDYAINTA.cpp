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
	long long T;
	cin >> T;
	while (T--){
		long long N;
		long long sum = 0;
		cin >> N;
		bool flag = true;
		vector<long long> arr;
		for (long long i = 0; i < N; i++) {
			long long buf;
			cin >> buf;
			arr.push_back(buf);
		}
		for (long long i = N - 1; i > 1; i--){
			if ((arr[i] + sum) % i == 0){ sum += (arr[i] + sum) / i; }
			else { flag = false; break; }
		}
		if (flag == false){ cout << "IMPOSSIBLE" << endl; }
		else{ cout << "POSSIBLE" << endl; }
	}
	system("pause");
}