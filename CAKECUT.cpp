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
#include<stack>
#define INF 1987654321
using namespace std;
int main() {
	while (true){
		int w, h, m;
		cin >> w >> h >> m;
		if (w == 0 && h == 0 && m == 0){ break;}
		vector<vector<vector<int > > > dp;
		for (int i = 0; i < 25; i++){
			vector<vector<int> > vvbuf;
			for (int j = 0; j < 25; j++){
				vector<int> vbuf;
				for (int k = 0; k < 25; k++){
					vbuf.push_back(INF);
				}
				vvbuf.push_back(vbuf);
			}
			dp.push_back(vvbuf);
		}
		for (int i = 1; i <= 20; i++){
			for (int j = 1; j <= 20; j++)	dp[i][j][1] = i*j;
		}
		for (int i = 0; i <= w; i++)for (int j = 0; j <= h; j++)for (int t = 0; t <= m; t++)dp[i][j][t] = 987654321;
		for (int i = 1; i <= w; i++){
			for (int j = 1; j <= h; j++){
				dp[i][j][1] = i*j;
				for (int t = 2; t <= i*j && t <= 20; t++){
					for (int a = 1; a<i; a++){
						for (int b = 1; b<t; b++){
							dp[i][j][t] = min(dp[i][j][t], max(dp[a][j][b], dp[i - a][j][t - b]));
						}
					}
					for (int a = 1; a<j; a++){
						for (int b = 1; b<t; b++){
							dp[i][j][t] = min(dp[i][j][t], max(dp[i][a][b], dp[i][j - a][t - b]));
						}
					}
				}
			}
		}
		cout << dp[w][h][m] << endl;
	}
	

}