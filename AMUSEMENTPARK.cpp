#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool IsClose(pair<int, int>& onePos, pair<int, int>& twoPos) {
	int y1 = onePos.first;
	int x1 = onePos.second;
	int y2 = twoPos.first;
	int x2 = twoPos.second;

	int diffy = abs(y1 - y2);
	int diffx = abs(x1 - x2);
	if (diffy <= 1 && diffx <= 1) { return true; }
	return false;
}
bool IsPrime(int one, int two) {
	int mmin = min(one, two);
	int cnt = 0;
	if (mmin == 0) { return false; }
	for (int i = 2; i <= mmin; i++) {
		if (one%i == 0 && two%i == 0) { return false; }
		//if (cnt > 1) { return false; }
	}
	return true;
}
bool IsPrimePair(pair<int, int>& onePos, pair<int, int>& twoPos) {
	int y1 = onePos.first;
	int x1 = onePos.second;
	int y2 = twoPos.first;
	int x2 = twoPos.second;

	int diffy = abs(y1 - y2);
	int diffx = abs(x1 - x2);
	if (IsPrime(diffy, diffx)) { return true; }
	return false;
}

//무조건 절대값 뱉게
vector<pair<int, int> > GetStep(pair<int, int> onePos, pair<int, int> twoPos) {
	vector<pair<int, int> > ret;
	int y1 = onePos.first;
	int x1 = onePos.second;
	int y2 = twoPos.first;
	int x2 = twoPos.second;

	int diffy = abs(y1 - y2);
	int diffx = abs(x1 - x2);
	if (diffy == 0) { ret.push_back(make_pair(0, 1)); return ret; }
	if (diffx == 0) { ret.push_back(make_pair(1, 0)); return ret; }

	int mmin = min(diffy, diffx);
	for (int i = 2; i <= mmin; i++) {
		if (diffy%i == 0 && diffx%i == 0) {
			if (!IsPrime(diffy / i, diffx / i)) { continue; }
			ret.push_back(make_pair(diffy/i, diffx/i));
		}
	}
	return ret;
}
bool CanSee(vector<vector<int> >& board, pair<int, int>& onePos, pair<int, int>& twoPos) {
	int dy = 1;
	int dx = 1;
	//방향 기준은 onePos에서 twoPos로 무조건 다가가는 형태.
	if (twoPos.first - onePos.first < 0) { dy *= -1; }
	if (twoPos.second - onePos.second < 0) { dx *= -1; }


	auto absStep = GetStep(onePos, twoPos);
	for (auto it = absStep.begin(); it != absStep.end(); it++) {
		int stepY = it->first * dy;
		int stepX = it->second * dx;
		int y2 = onePos.first;
		int x2 = onePos.second;
		while (true) {
			y2 += stepY;
			x2 += stepX;
			if (y2 == twoPos.first && x2 == twoPos.second) { return true; }
			if (board[y2][x2] != 0) { return false; }
		}

	}
	return true;
}

void solve(vector<vector<int> >& board, map<int, pair<int, int> >& mutatedBoard, int two, int end) {
	int one = 1;
	set<int> ret;

	for (int i = two; i <= end; i++) {
		int one = i - two + 1;
		pair<int, int> onePos = mutatedBoard[one];
		pair<int, int> twoPos = mutatedBoard[i];
		if (IsClose(onePos, twoPos)) { ret.insert(one); continue; }
		if (IsPrimePair(onePos, twoPos)) { ret.insert(one); continue; }
		if (CanSee(board, onePos, twoPos)) { ret.insert(one); continue; }
	}
	cout << ret.size() << endl;
	for (auto it = ret.begin(); it != ret.end(); it++) { cout << *it << endl; }
}
int main() {

	int Y, X, two;
	cin >> Y >> X >> two;
	vector<vector<int> > board = vector<vector<int> >(Y, vector<int>(X, 0));
	map<int, pair<int, int> > mutatedBoard;
	int end = -1;
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			int v;
			cin >> v;
			end = max(end, v);
			board[i][j] = v;
			if (v > 0) {
				mutatedBoard[v] = make_pair(i, j);
			}
		}
	}
	solve(board, mutatedBoard, two, end);
}