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
vector<int> cache;
bool isfinish(const vector<string>& board, char turn) {
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == turn){ return true; }
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == turn){ return true; }

	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == turn){ return true; }
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == turn){ return true; }
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == turn){ return true; }

	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == turn){ return true; }
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == turn){ return true; }
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == turn){ return true; }


	return false;
}


int getid(const vector<string>& board) {
	int ret = 0;
	for (int y = 0; y < 3; y++){
		for (int x = 0; x < 3; x++){
			ret *= 3;
			if (board[y][x] == '.'){
				ret += 0;
			}
			if (board[y][x] == 'o'){
				ret += 1;
			}
			if (board[y][x] == 'x'){
				ret += 2;
			}

		}
	}
	return ret;
}


int solve(vector<string>& board, char turn) {
	if (isfinish(board, 'o' + 'x' - turn)) { return -1; }
	int& ret = cache[getid(board)];
	if (ret != -2) return ret;
	int mmin = 2;
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				mmin = min(mmin, solve(board, 'o' + 'x' - turn));
				board[y][x] = '.';
			}
		}
	if (mmin == 2 || mmin == 0) { return ret = 0; }
	return ret = -mmin;
}
char calcturn(vector<string> board){
	char ret = '@';
	int o = 0;
	int x = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] == 'o'){ o++; }
			if (board[i][j] == 'x'){ x++; }
		}
	}
	if (o >= x){ return 'x'; }
	if (o < x){ return 'o'; }
}

int main() {
	int  T;
	cin >> T;
	while (T--){
		vector<string> board;
		cache.clear();
		for (int i = 0; i < 50000; i++){ cache.push_back(-2); }
		for (int i = 0; i < 3; i++){
			string s;
			cin >> s;
			board.push_back(s);
		}
		char turn = calcturn(board);
		int result = solve(board, turn);
		if (result == 1){ cout << turn << endl; }
		else if (result == 0){ cout << "TIE" << endl; }
		else if (result == -1)
		{
			if (turn == 'o'){ cout << 'x' << endl; }
			else{ cout << 'o' << endl; }
		}

	}

	system("pause");
}