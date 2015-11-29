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
using namespace std;
int solve(vector<vector<int> >& board, vector<vector<int> >& cache, int n, int depth){
	if (n < 0){ return 0; }
	if (depth == board.size()){ return 0; }
	if (n >= board[depth].size()){ return 0; }
	int& ret = cache[depth][n];
	if (ret != -1){ return ret; }
	try{
		ret = board[depth][n];
	}
	catch (...) { return 0; }
	if (depth + 1 < (board.size() + 1) / 2){
		ret += max(solve(board, cache, n, depth + 1), solve(board, cache, n + 1, depth + 1));
	}
	else{
		ret += max(solve(board, cache, n, depth + 1), solve(board, cache, n - 1, depth + 1));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int n;
		vector<vector<int> > diamond;
		vector<vector<int> > cache;
		cin >> n;
		for (int i = 0; i < n * 2 + 1; i++){
			vector<int> vbuf;
			for (int j = 0; j < n * 2 + 1; j++){ vbuf.push_back(-1); }
			cache.push_back(vbuf);
		}

		for (int i = 0; i < n; i++){
			vector<int> vbuf;
			for (int j = 0; j <= i; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			diamond.push_back(vbuf);
		}
		for (int i = n - 1; i > 0; i--){
			vector<int> vbuf;
			for (int j = 0; j < i; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			diamond.push_back(vbuf);
		}


		cout << solve(diamond, cache, 0, 0) << endl;
	}
	system("pause");
}