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
#define MOD 1000000007
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<vector<vector<int> > > cache(2,vector<vector<int> >(N+10,vector<int>(K+10,0)));
		cache[0][0][0] = 1;
		cache[0][0][1] = 1;
		cache[1][0][0] = 1;
		for (int i = 1; i < N; i++){
			for (int j = 0; j <= N; j++){
				for (int k = 1; k <= K; k++){
					int use = cache[(i - 1) % 2][(j - i + N) % N][k - 1];
					int notuse = cache[(i-1)%2][j][k];
					cache[i % 2][j][k] = (use + notuse) % MOD;
				}
			}
		}
		cout << cache[(N - 1) % 2][0][K] << endl;
	}
	system("pause");
}