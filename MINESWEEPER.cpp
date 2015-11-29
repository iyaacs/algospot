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
const int dy[8] = {-1,-1,-1,0,1,1,1,0 };
const int dx[8] = {-1,0,1,1,1,0,-1,-1 };
bool isbound(vector<vector<int > >& adj, int y, int x){
	if (y < 0 || x < 0){ return false; }
	int Y = adj.size();
	if (y >= Y){ return false; }
	int X = adj[y].size();
	if (x >= X){ return false; }
	return true;
}
void dfs(vector<vector<int> >& adj, vector<vector<bool> >& visited, int y, int x){
	visited[y][x] = true;
	for (int i = 0; i < 8; i++){
		int y2 = y + dy[i];
		int x2 = x + dx[i];
		if (isbound(adj, y2, x2)){
			if (!visited[y2][x2]){
				if (adj[y2][x2] == 0){ dfs(adj, visited, y2, x2); }
			}
		}
	}
}
int dfsall(vector<vector<int> >& adj){
	int ret = 0;
	vector<vector<bool> > visited(adj.size(), vector<bool>(adj[0].size(), false));
	for (int i = 0; i < adj.size(); i++){
		for (int j = 0; j < adj[i].size(); j++){
			if (!visited[i][j]){
				if (adj[i][j] == 0){
					dfs(adj, visited, i, j);
					ret++;
				}
			}
		}
	}
	return ret;
}
int solve1(vector<string>& board, vector<vector<int> >& adj){
	int Y = board.size();
	int X = board[0].size();
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (board[i][j] == '*'){
				for (int k = 0; k < 8; k++){
					int y2 = i + dy[k];
					int x2 = j + dx[k];
					if (isbound(adj, y2, x2)){
						adj[y2][x2]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (board[i][j] == '*'){
				adj[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (adj[i][j] == 0){
				for (int k = 0; k < 8; k++){
					int y2 = i + dy[k];
					int x2 = j + dx[k];
					if (isbound(adj, y2, x2)){
						if (adj[y2][x2] > 0){ adj[y2][x2] = -2; }
					}
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			if (adj[i][j] > 0){ ret++; }
		}
	}
	return ret + dfsall(adj);

}
int main(){
	int T;
	cin >> T;
	while (T--){
		int Y, X;
		cin >> Y >> X;
		vector<string> board;
		for (int i = 0; i < Y; i++){
			string s;
			cin >> s;
			board.push_back(s);
		}
		vector<vector<int> > adj(Y,vector<int>(X,0));
		cout<<solve1(board, adj)<<endl;
	}
	system("pause");
}