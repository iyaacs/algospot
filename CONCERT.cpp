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
using namespace std;
#define INF 987654321
bool solve2(vector<int>& volume, vector<vector<char> >& cache2, int curr, int n, int VM){
	if (curr<0){ return false; }
	if (curr>VM){ return false; }
	if (n > volume.size()){ return false; }
	char& ret = cache2[n][curr];
	if (ret != -1){ return ret; }
	ret = true;
	int plus = curr + volume[n];
	int minus = curr - volume[n];
	solve2(volume, cache2, plus, n + 1, VM);
	solve2(volume, cache2, minus, n + 1, VM);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, VS, VM;
		vector<int> VOLUME;
		vector<vector<char> >cache2;
		
		scanf("%d%d%d", &N, &VS, &VM);
		for (int i = 0; i <= N; i++){
			vector<char> vbuf;
			for (int j = 0; j <= VM; j++){ vbuf.push_back(-1); }
			cache2.push_back(vbuf);
		}

		for (int i = 0; i < N; i++){
			int buf;
			scanf("%d", &buf);
			VOLUME.push_back(buf);
		}

		solve2(VOLUME, cache2, VS, 0, VM);
		int flag = 0;
		for (int i = VM; i >= 0; i--){
			if (cache2[N][i] != -1){ printf("%d\n",i); flag = 1; break; }
		}
		if (flag == 0){ printf("-1\n"); }
		
	}
}