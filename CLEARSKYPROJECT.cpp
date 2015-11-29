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
#define INF 1987654321
using namespace std;

int main(){
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<pair<int, int> > cloud;
		cloud.push_back(make_pair(0, 0));
		for (int i = 0; i < N; i++){
			int a, b;
			cin >> a >> b;
			cloud.push_back(make_pair(a, b));
		}
		sort(cloud.begin() + 1, cloud.end());
		vector<vector<int> > cache;
		for (int i = 0; i < K+10; i++){
			vector<int> vbuf;
			for (int j = 0; j < N+10; j++){ vbuf.push_back(INF); }
			cache.push_back(vbuf);
		}
		cache[0][0] = 0;
		for (int i = 0; i < K; i++){
			for (int j = 0; j < N; j++){
				if (cache[i][j] >= INF){ continue; }
				else{
					int ret = INF;
					for (int k = j + 1; k <= N; k++){
						if (ret>cloud[k].second){ ret = cloud[k].second; }
						if (cloud[k].first > ret){ break; }
						if (cache[i + 1][k] > cache[i][j] + cloud[k].first*(k - j)){
							cache[i + 1][k] = cache[i][j] + cloud[k].first*(k - j);
						}
					}
				}
			}
		}
			int ans = INF;
			for (int i = 1; i <= K; i++){
				ans = min(ans, cache[i][N]);
			}
			cout << ans << endl;
		}

	system("pause");
}