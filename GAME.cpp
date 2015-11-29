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
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, K;
		cin >> N >> K;
		vector<vector<int> > board;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < K; j++){
				int buf;
				cin >> buf;
				buf--;
				vbuf.push_back(buf);
			}
			board.push_back(vbuf);
		}
		vector<bool> check(N, false);
		vector<int> loser;
		bool flag = true;
		for (int i = 0; i < K; i++){
			loser.clear();
			int mmin = INF;
			for (int j = 0; j < N; j++){
				if (check[j] == false){
					mmin = min(mmin, board[j][i]);
				}
			}
			for (int j = 0; j < N; j++){
				if (board[j][i] == mmin && check[j] == false){
					check[j] = true;
					loser.push_back(j);
				}				
			}
			if (loser.size()>1){ flag = false; break; }
		}
		if (flag == false){
			for (int i = 0; i < loser.size(); i++){ 
				cout << loser[i] + 1 << " ";
			}
			cout << endl;
		}
		else{
			for (int i = 0; i < check.size(); i++){
				if (check[i] == false){ 
					cout << i + 1 << " ";
				}
			}
			cout << endl;
		}

	}

	system("pause");
}