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
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<int> arr;
		list<int> la;
		arr.push_back(0);
		for (int i = 0; i < N; i++){
			arr.push_back(1);
		}
		int iter = 1;
		for (int i = 0; i < N - 2; i++){
			int addval = 0;
			arr[iter] = 0;
			while (true){
				iter++;
				iter = iter % (N + 1);
				if (arr[iter] == 1){ addval++; }
				if (addval == K){ break; }
			}
		}
		int g = 0;
		for (int i = 0; i < N + 1; i++){
			if (arr[i] == 1){ cout << i << " "; arr[i] = 0; g = i; break; }
		}
		for (int i = g; i < N + 1; i++){
			if (arr[i] == 1){ cout << i << endl; }
		}
	}
	system("pause");
}