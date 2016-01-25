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
using namespace std;
const int dy[] = {1,1};
const int dx[] = {-1,1};
void mutate(vector<string>& board, vector<vector<vector<int> > >& n2id, vector<vector<int> >& adj, int& n, int& m){
	vector<int> cnt(2, 0);
	for (int y = 0; y < board.size(); y++){
		for (int x = 0; x < board[0].size(); x++){
			for (int d = 0; d < 2; d++){
				if (board[y][x] == '.' && n2id[y][x][d] == -1){
					int y2 = y;
					int x2 = x;
					while (true){
						if (y2 < 0){ break; }
						if (y2 >= board.size()){ break; }
						if (x2 < 0){ break; }
						if (x2 >= board[0].size()){ break; }
						if (board[y2][x2] != '.'){ break; }
						n2id[y2][x2][d] = cnt[d];
						y2 += dy[d];
						x2 += dx[d];
						
					}
					cnt[d]++;
				}
			}
		}
	}

	n = cnt[0];
	m = cnt[1];
	for (int y = 0; y < board.size(); y++){
		for (int x = 0; x < board[0].size(); x++){
			if (board[y][x] == '.'){ adj[n2id[y][x][0]][n2id[y][x][1]] = 1; }
		}
	}
}
bool dfs(vector<vector<int> >& adj, int n, int m, vector<bool>& visited, vector<int>& amatch, vector<int>& bmatch, int here){
	if (visited[here]){ return false; }
	visited[here] = true;
	for (int dst = 0; dst < m; dst++){
		if (adj[here][dst]){
			if (bmatch[dst] == -1 || dfs(adj,n,m,visited,amatch,bmatch,bmatch[dst])){
				amatch[here] = dst;
				bmatch[dst] = here;
				return true;
			}
		}
	}
	return false;
}
inline int bimatch(vector<vector<int> >& adj, int n, int m){
	vector<int> amatch = vector<int>(n, -1);
	vector<int> bmatch = vector<int>(m, -1);
	int size = 0;
	for (int start = 0; start < n; start++){
		vector<bool> visited = vector<bool>(n, false);
		if (dfs(adj,n,m,visited,amatch,bmatch,start)){ size++; }
	}
	return size;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<string> board;
		vector<vector<vector<int> > > n2id(N, vector<vector<int> >(N, vector<int>(2, -1)));
		vector<vector<int> > adj(N*N, vector<int>(N*N, 0));
		//y, x, dir
		for (int i = 0; i < N; i++){
			string s;
			cin >> s;
			board.push_back(s);
		}
		int n, m;
		mutate(board, n2id, adj,n,m);
		cout << bimatch(adj, n, m) << endl;

	}

	system("pause");
}