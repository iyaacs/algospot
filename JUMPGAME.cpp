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
#define INF 1987654321
using namespace std;
vector<vector<int> > cache;

//사실 bool로 해도 되는데, -1이라는 값을 이용하려고 int를 씀.
int solve(vector<vector<int> >& board, int nowy, int nowx){
	int N = board.size();
	if (nowx >= N){ return false; }//0
	if (nowy >= N){ return false; }//0
	if (nowx == N - 1 && nowy == N - 1){ return true; }//1
	
	
	
	int& ret=cache[nowy][nowx];
	if(ret!=-1){return ret;}
	ret=false;
	
	
	int next = board[nowy][nowx]; // 몇칸을 뛸지
	
	ret=max(ret,solve(board, nowy + next, nowx));
	//사실 or연산이랑 같음. (하나라도 1이면 경로가 있다는거기 때문)
	//밑으로 next칸
	ret=max(ret,solve(board, nowy, nowx + next));
	//오른쪽으로 next칸
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T --){
		int N;
		cin >> N;
		vector<vector<int> > board;
		cache.clear();
		for(int i=0; i<N;i++){
		    vector<int> vbuf;
		    for(int j=0; j<N;j++){
		        vbuf.push_back(-1);
		    }
		    cache.push_back(vbuf);
		}
		
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < N; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			board.push_back(vbuf);
		}
		
		if (solve(board, 0, 0)){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }

	}	
	system("pause");
}