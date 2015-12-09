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
int gridsum(vector<vector<int> >& psum, int y1, int x1, int y2, int x2){
	int ret = psum[y2][x2];
	if (y1 > 0){ ret -= psum[y1 - 1][x2]; }
	if (x1 > 0){ ret -= psum[y2][x1 - 1]; }
	if (y1 > 0 && x1 > 0){ ret += psum[y1 - 1][x1 - 1]; }
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		N++;
		vector<vector<int> > adj(N, vector<int>(N, 0));
		for (int i = 1; i < N; i++){
			int psum1 = 0;
			for (int j = 1; j < N; j++){
				int psum2 = adj[i - 1][j];
				int buf;
				cin >> buf;
				psum1 += buf;
				adj[i][j] = (psum1 + psum2);
			}
		}
		int mmax = -INF;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				for (int i2 = i+1; i2 < N; i2++){
					for (int j2 = j+1; j2 < N; j2++){
						mmax = max(mmax, gridsum(adj,i,j,i2,j2));
					}
				}
			}
		}
		cout << mmax << endl;

	}
	system("pause");
}