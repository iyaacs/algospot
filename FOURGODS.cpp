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
long long combi(long long N){
	if (N == 0){ return 0; }
	if (N == 1){ return 0; }
	return (N*(N - 1)) / 2;
}
int main(){
		long long T;
		cin >> T;
		while (T--){
			long long N, M;
			cin >> N >> M;
			vector<vector<bool> > adj(N, vector<bool>(N, 0));
			for (long long i = 0; i < M; i++){
				long long a, b;
				cin >> a >> b;
				a--; b--;
				adj[a][b] = 1;
				adj[b][a] = 1;
			}
			long long ret = 0;
			for (long long i = 0; i < N; i++){
				for (long long j = i+1; j < N; j++){
					long long cache=0;
					for (long long k = 0; k < N; k++){
						if (k == i){ continue; }
						if (k == j){ continue; }
						if (adj[i][k] == 1 && adj[j][k] == 1){ cache++; }
					}
					ret += combi(cache);
				}
			}	
			cout << (ret/2)%20130728 << endl;
		}

		system("pause");
	}