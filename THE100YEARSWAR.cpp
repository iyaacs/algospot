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
using namespace std;
void preorder(vector<vector<int> >& child, int a, int& serial, vector<int>& no2serial, vector<int>& lastdescend){
	no2serial[a] = serial;
	serial++;
	for (int childn : child[a])
		preorder(child,childn,serial,no2serial,lastdescend);
	lastdescend[a] = serial - 1;
	return;
}
void backhead(int a,vector<int>& team, vector<int>& no2serial, vector<int>& lastdescend){
	for (int i = no2serial[a]; i <= lastdescend[a]; i++)
		team[i] ^= true;
}
bool isteam(int a, int b, vector<int>& team, vector<int>& no2serial){
	if (team[no2serial[a]] == team[no2serial[b]]){ return true; }
	return false;
}



int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, Q;
		cin >> N >> Q;
		vector<vector<int> > child;
		for (int i = 0; i < N+1; i++){
			vector<int> vbuf;
			child.push_back(vbuf);
		}
		for (int i = 0; i < N - 2; i++){
			int a, b;
			cin >> a >> b;
			child[a].push_back(b);
		}
		vector<int> team(N+1, 0);
		vector<int> no2serial(N+1);
		vector<int> lastdescend(N+1);
		int serial = 1;
		preorder(child, 1, serial, no2serial, lastdescend);
		preorder(child, 2, serial, no2serial, lastdescend);
		backhead(2, team, no2serial, lastdescend);
		for (int i = 0; i < Q; i++){
			string a;
			int b; 
			int c;
			cin >> a;
			if (a == "Q"){ 
			cin >> b >> c; 
			if (isteam(b, c, team, no2serial)){ cout << "Ally" << endl; }
			else{ cout << "Enemy" << endl; }
			}
			else{
				cin >> b; 
			backhead(b, team, no2serial, lastdescend);
			}
		}

	}
	system("pause");
}