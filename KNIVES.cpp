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
#define INF 1987654321
using namespace std;
int H, W, L, A, CT, TL;
vector<string> board;
vector<vector<int> > attackcache;
int cache[55][55][110][11];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
void init(){
	board.clear();
	attackcache.clear();
	for (int i = 0; i < 55; i++){
		for (int j = 0; j < 55; j++){
			for (int k = 0; k < 110; k++){
				for (int l = 0; l < 11; l++){
					cache[i][j][k][l] = -1;
				}
			}
		}
	}
}
int dist(int y, int x, int y2, int x2){
	return abs(y2 - y) + abs(x2 - x);
}
bool isbound(int y, int x){
	if (y < 0){ return false; }
	if (x < 0){ return false; }
	if (y >= board.size()){ return false; }
	if (x >= board[0].size()){ return false; }
	if (board[y][x] == 'x'){ return false; }
	return true;
}
int dmg(char c){
	if (c < '0'){ return false; }
	if (c > '9'){ return false; }
	int B = c - '0';
	return max(0, (A - B));
}
int attack(int y, int x){
	int ret = 0;
	for (int y2 = 0; y2<board.size(); y2++){
		for (int x2 = 0; x2<board[0].size(); x2++){
			if (!isbound(y2, x2)){ continue; }
			if (dist(y, x, y2, x2) > L){ continue; }
			ret += dmg(board[y2][x2]);
		}
	}
	return ret;
}
void genattack(){
	int Y = board.size();
	int X = board[0].size();
	for (int i = 0; i < Y; i++){
		vector<int> vbuf(X, 0);
		attackcache.push_back(vbuf);
	}
	for (int i = 0; i < Y; i++){
		for (int j = 0; j < X; j++){
			attackcache[i][j] = attack(i, j);
		}
	}
}
int solve(int y, int x, int time, int cool){
	if (time <= 0){ return 0; }
	if (!isbound(y, x)){ return 0; }
	int& ret = cache[y][x][time][cool];
	if (ret != -1){ return ret; }
	ret = 0;
	if (cool > 0){
		int pv = solve(y, x, time - 1, cool - 1);
		for (int i = 0; i < 4; i++){
			int y2 = y + dy[i];
			int x2 = x + dx[i];
			pv = max(pv, solve(y2, x, time - 1, cool - 1));
			pv = max(pv, solve(y, x2, time - 1, cool - 1));
		}
		ret += pv;
	}
	
	if (cool <= 0){
		int pv = solve(y, x, time - 1, max(cool - 1, 0));
		for (int i = 0; i < 4; i++){
			int y2 = y + dy[i];
			int x2 = x + dx[i];
			pv = max(pv, solve(y2, x, time - 1, max(cool - 1, 0)));
			pv = max(pv, solve(y, x2, time - 1, max(cool - 1, 0)));
		}
		pv = max(pv,solve(y, x, time - 1, CT) + attackcache[y][x]);
		ret += pv;
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> H >> W >> L >> A >> CT >> TL;
		//H : Height
		//W : Width
		//L : 사거리
		//A : 공격력
		//CT: 쿨타임
		//TL: 타임

		init();
		for (int i = 0; i < H; i++){
			string s;
			cin >> s;
			board.push_back(s);
		}
		genattack();
		cout << solve(0, 0, TL, 0) << endl;
	}
	system("pause");
}