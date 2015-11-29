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
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		bool goodflag=true;
		int N, M;
		cin >> N >> M;
		vector<int> problem;
		for (int i = 0; i < M; i++){ problem.push_back(0); }

		for (int i = 0; i < N; i++){
			int X;
			cin >> X;
			if (X == 0 || X==M){ goodflag = false; }
			for (int j = 0; j < X; j++){
				int prob;
				cin >> prob;
				prob--;
				problem[prob]++;
			}
		}
		int mmin = INF;
		int mmax = 0;
		for (int i = 0; i < M; i++){
			mmin = min(mmin, problem[i]);
			mmax = max(mmax, problem[i]);
		}
		if (mmin == 0){ goodflag = false; }
		if (mmax == M){ goodflag = false; }
		if (goodflag){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
	}
	system("pause");
}