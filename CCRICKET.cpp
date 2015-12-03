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
#define INF 987654321
using namespace std;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int H;
int W;
vector<string> board;
vector<vector<bool> > adj;
vector<int> amatch;
vector<int> bmatch;
vector<bool> visited;
int n;
int m;
int P1, P2;
void init(){
	H = 0;
	W = 0;
	board.clear();
	adj.clear();
	amatch.clear();
	bmatch.clear();
	visited.clear();
	n = 0;
	m = 0;
	P1 = 0;
	P2 = 0;
}
bool inrange(int y, int x){
	if (y < 0){ return false; }
	if (x < 0){ return false; }
	if (y >= H){ return false; }
	if (x >= W){ return false; }
	return true;
}
bool dfs(int here){
	if (visited[here]){ return false; }
	visited[here] = true;
	for (int dst = 0; dst < m; dst++){
		if (adj[here][dst]){
			if (bmatch[dst] == -1 || dfs(bmatch[dst])){
				amatch[here] = dst;
				bmatch[dst] = here;
				return true;
			}
		}
	}
	return false;
}

int bimatch(){
	amatch = vector<int>(n, -1);
	bmatch = vector<int>(m, -1);
	int size = 0;
	for (int start = 0; start < n; start++){
		visited = vector<bool>(n, false);
		if (dfs(start)){ size++; }
	}
	return size;
}

int solve(){
	int one = 0;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (board[i][j] == '0'){ one++; }
		}
	}
	if (P1 * 2 <= P2){
		return one*P1;
	}

	vector<vector<int> > id(H, vector<int>(W, -1));
	n = 0;
	m = 0;
	for (int y = 0; y < H; y++){
		for (int x = 0; x < W; x++){
			if (board[y][x]=='0'){
				if ((y + x) % 2 == 0){ id[y][x] = n++; }
				else{ id[y][x] = m++; }
			}
		}
	}
	for (int i = 0; i < n; i++){
		vector<bool> vbuf(m, false);
		adj.push_back(vbuf);
	}
	for (int y1 = 0; y1 < H; y1++){
		for (int x1 = 0; x1 < W; x1++){
			if ((y1+x1)%2==0 && board[y1][x1]=='0'){
				for (int k = 0; k < 4; k++){
					int y2 = y1 + dy[k];
					int x2 = x1 + dx[k];
					if (inrange(y2, x2) && board[y2][x2] == '0'){
						adj[id[y1][x1]][id[y2][x2]] = true;
					}
				}
			}
		}
	}
	int two = bimatch();
	one -= (two*2);

	return one*P1 + two*P2;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		init();
		cin >> H >> W >> P1 >> P2;
		for (int i = 0; i < H; i++){
			string s;
			cin >> s;
			board.push_back(s);
		}
		cout << solve() << endl;
	}
	system("pause");
}