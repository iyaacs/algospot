#define  _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<algorithm>
#include <functional>
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

bool solve(vector<string>& board, vector<pair<int, int> >& position, char c) {
	for (int i = 0; i < position.size(); i++) {
		for (int j = i + 1; j < position.size(); j++) {
			int y1 = position[i].first;
			int x1 = position[i].second;
			int y2 = position[j].first;
			int x2 = position[j].second;

			int dy = y2 - y1;
			int dx =x2 - x1;
			int y3 = y1 - dx;
			int x3 = x1 + dy;
			int y4 = y3 + dy;
			int x4 = x3 + dx;

			if (y3 < 0 || y4 < 0) { continue; }
			if (x3 < 0 || x4 < 0) { continue; }
			if (y3 > 10 || y4 > 10) { continue; }
			if (x3 > 10 || x4 > 10) { continue; }
			if (board[y3][x3] == c && board[y4][x4] == c) { return true; }
		}
	}
	return false;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		vector<pair<int, int> > bluePos;
		vector<pair<int, int> > redPos;
		vector<string> board;
		for (int y = 0; y < 11; y++) {
			string s;
			cin >> s;
			board.push_back(s);
			for (int x = 0; x < 11; x++) {
				char c = s[x];
				if (c == 'B') { bluePos.push_back(make_pair(y, x)); }
				if (c == 'R') { redPos.push_back(make_pair(y, x)); }
			}
			
		}
		if (solve(board, bluePos, 'B')) { cout << "Blue" << endl; }
		else if (solve(board, redPos, 'R')) { cout << "Red" << endl; }
		else {
			cout << "No squares" << endl;
		}
	}
	system("pause");
}