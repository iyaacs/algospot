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
int solve1(vector<pair<int, int> >& board, int left, int right){
	int ret = 0;
	for (int i = left; i < right; i++){
		ret = max(ret, board[i].second);
	}
	return ret;
}

int solve2(vector<pair<int, int> >& board){
	int left = -1;
	int right = -1;
	int N = board.size()-1;
	int ret = 0;
	int now = -1;
	int idx = 0;
	for (int i = 0; i < N+1; i++){
		if (now + 1 < board[i].first){
			ret++;
			//cout << idx << " " << i << endl;
			now = solve1(board, idx, i);
			idx = i;
			if (now >= N - 1){ break; }
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<pair<int, int> > board;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			int front = max(0, (i - (buf - 1)));
			int end = i + (buf - 1);
			board.push_back(make_pair(front, end));
		}
		sort(board.begin(), board.end());
		board.push_back(make_pair(INF, INF));
		for (int i = 0; i < board.size(); i++){
			//cout << board[i].first << " " << board[i].second << endl;
		}
		cout << solve2(board) << endl;
	}
	system("pause");
}