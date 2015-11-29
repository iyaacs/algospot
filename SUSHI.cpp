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
#include<limits>
#define INF 987654321
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int n, m;
		cin >> n >> m;
		m /= 100;
		vector<int> sushi;
		vector<int> like;
		for (int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			a /= 100;
			sushi.push_back(a);
			like.push_back(b);
		}
		vector<int> cache;
		for (int i = 0; i < 201; i++){ cache.push_back(0); }
		int ret = 0;
		for (int i = 1; i <= m; i++){
			int cand = 0;
			for (int j = 0; j < n; j++){
				if (i >= sushi[j]){
					cand = max(cand, cache[(i-sushi[j])%201]+like[j]);
				}
			}
			cache[i % 201] = cand;
			ret = max(ret, cand);
		}
		cout << ret << endl;
	}
	system("pause");
}