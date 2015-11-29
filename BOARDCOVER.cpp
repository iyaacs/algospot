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
int cover[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } }
};
bool put(vector<vector<int> >& board, int y, int x, int type, int flag){
	bool ret = true;
	for (int i = 0; i < 3; i++){
		int ny = y + cover[type][i][0];
		int nx = x + cover[type][i][1];
		if (ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size()){ ret= false; }
		else if ((board[ny][nx] += flag) > 1){ ret = false; }
	}
	return ret;
}
int solve(vector<vector<int> >& board){
	int y = -1;
	int x = -1;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j] == 0){ y = i; x = j; break; }
		}
		if (y != -1){ break; }
	}
	if (y == -1){ return 1; }
	int ret = 0;
	for (int type = 0; type < 4; type++){
		if (put(board, y, x, type, 1)){ ret += solve(board); }
		put(board, y, x, type, -1);
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int H, W;
		cin >> H >> W;
		vector<vector<int> > board;
		for (int i = 0; i < H; i++){
			string s;
			cin >> s;
			vector<int> vbuf;
			for (int j = 0; j < s.length(); j++){
				if (s[j] == '.'){ vbuf.push_back(0); }
				else{ vbuf.push_back(1);	 }
			
			}
			board.push_back(vbuf);
		}

		cout << solve(board) << endl;


	}
	system("pause");
}