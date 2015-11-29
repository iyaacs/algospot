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
#define INF 1987654321;
using namespace std;
int solve(vector<vector<int>>& tri, vector<vector<int>>& cache, int y, int x){
	if (tri.size() == y + 1){ return tri[y][x]; }
	if (tri[y].size() == x){ return 0; }
	int& ret = cache[y][x];
	if (ret != -1){ return ret; }
	ret = max(solve(tri,cache,y+1,x+1),solve(tri,cache,y+1,x))+tri[y][x];
	return ret;
}

int sumsolve(vector<vector<int>>& sumtri, vector<vector<int>>& sumcache, int y, int x){
	if (y == sumtri.size() - 1){ return 1; }
	int& ret = sumcache[y][x];
	if (ret != -1){ return ret; }
	
	ret = 0;
	if (sumtri[y + 1][x + 1] >= sumtri[y + 1][x]){ ret += sumsolve(sumtri,sumcache,y+1,x+1); }
	if (sumtri[y+1][x+1]<=sumtri[y+1][x]){ ret += sumsolve(sumtri,sumcache,y+1,x); }
	return ret;
}

int main(){
std::ios::sync_with_stdio(false);
int T;
cin >> T;
while (T--){
	int n;
	vector<vector<int>> tri;
	vector<vector<int>> cache;
	vector<vector<int>> sumtri;
	vector<vector<int>> sumcache;
	for (int i = 0; i < 101; i++){
		vector<int> vbuf;
		for (int j = 0; j < 101; j++){
			vbuf.push_back(-1);
		}
		cache.push_back(vbuf);
		sumcache.push_back(vbuf);
	}

	cin >> n;
	for (int i = 0; i < n; i++){
		vector<int> vbuf;
		for (int j = 0; j <= i; j++){
			int buf;
			cin >> buf;
			vbuf.push_back(buf);
		}
		tri.push_back(vbuf);
	}

	solve(tri, cache, 0, 0);
	


	//////////////////////
	for (int i = 0; i < n; i++){
		vector<int> vbuf;
		for (int j = 0; j <= i; j++){
			vbuf.push_back(cache[i][j]);
		}
		sumtri.push_back(vbuf);
	}



	for (int i = 0; i < n; i++){
		sumtri[n - 1][i] = tri[n - 1][i];
	}


	cout << sumsolve(sumtri, sumcache, 0, 0) << endl;

}
system("pause");
}