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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 1987654321;
using namespace std;
void calcoverlap(vector<string>& str, vector<vector<int> >& overlap){
	int N = str.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == j){ continue; }
			string str1 = str[i];
			string str2 = str[j];
			int val = 0;
			string needle1 = "";
			string needle2 = "";
			int idx = str1.size();
			idx = min(idx, (int)(str2.size()));
			for (int k = 0; k < idx; k++){
				needle1 = str1[str1.size() - 1 - k] + needle1;
				needle2 += str2[k];
			//	cout << needle1 << " " << needle2 << endl;
				if (needle1 == needle2){ val = k+1; }
			}
			overlap[i][j] = val;
		}
	}
}
int solve1(vector<vector<int> >& overlap, vector<vector<int> >& cache, int here, int visited){
	int N = overlap.size();
	if (visited == ((1 << N) - 1)){ return 0; }
	int& ret = cache[here][visited];
	if (ret != -1){ return ret; }
	ret = 0;
	for (int next = 0; next < N; next++){
		if (visited&(1 << next)){ continue; }
		int cand = overlap[here][next] + solve1(overlap, cache, next, visited + (1 << next));
		ret = max(ret, cand);
	}
	return ret;
}
string solve2(vector<string>& str,vector<vector<int> >& overlap, vector<vector<int> >& cache, int here, int visited){
	int N = overlap.size();
	if (visited == (1 << N) - 1){ return ""; }
	for (int next = 0; next < N; next++){
		if (visited&(1 << next)){ continue; }
		int val = overlap[here][next] + solve1(overlap,cache,next, visited + (1<<next));
		if (val == solve1(overlap, cache, here, visited)){
			return (str[next].substr(overlap[here][next]))+solve2(str,overlap,cache,next,visited+(1<<next));
		}
	}
}
void solve3(vector<string>& str, vector<vector<int> >& overlap){
	int N = overlap.size();
	int ret = 0;
	int here = 0;
	for (int i = 0; i < N; i++){
		vector<vector<int> > cache(N, vector<int>((1 << N), -1));
		int visited = (1<<i);
		int val = solve1(overlap, cache, i, visited);
		if (ret<val){ ret = val; here = i; }
	}
	vector<vector<int> > cache(N, vector<int>((1 << N), -1));
	int visited = 1<<here;
	cout << str[here]+solve2(str, overlap, cache, here, visited)<<endl;
}
void init(vector<string>& str){
	int N = str.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == j){ continue; }
			int find = str[i].find(str[j]);
			if (find != std::string::npos){ str[j] = ""; }
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<string> str;
		vector<vector<int> > overlap(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++){
			string s;
			cin >> s;
			str.push_back(s);
		}
		init(str);
		calcoverlap(str, overlap);
		solve3(str,overlap);
	}
	system("pause");
}