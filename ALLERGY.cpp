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
#include<hash_map>
#define INF 1987654321
#define MOD 1000000007
using namespace std;
bool solve(int N,vector<int>& picked, vector<vector<int> >& food){
	//cout << N << " " << picked.size() << " " << food.size() << endl;
	//cout << "A" << endl;
	vector<bool> edible;
	for (int i = 0; i < N; i++){
		edible.push_back(false);
	}
	//cout << "B" << endl;
	for (int i = 0; i < picked.size(); i++){
		for (int j = 0; j < food[picked[i]].size(); j++){
			
			int value = food[picked[i]][j];
			//cout << i << " " << j << " " << picked[i] << " " << food.size() << endl;
			//cout << value << endl;
			edible[value] = true;
		}
	}
	//cout << "C" << endl;
	for (int i = 0; i < N; i++){
		//cout << edible[i] << " ";
	}
	//cout << endl;
	for (int i = 0; i < N; i++){
		if (edible[i] == false){ return false; }
	}
	return true;	
}
void pick(int n, int r, vector<int>& picked, map<int,int>& selected, vector<vector<int> >& food, int &r2, int human){
	if (r2 == -1){ return; }
	if (r == 0){
		if (solve(human, picked, food)){ cout << r2 << endl; r2 = -1; }
		return;
	}
	int smallest = -1;
	if (picked.size() == 0){ smallest = 0; }
	else{ smallest = picked.back(); }
	for (int i = smallest; i < n; i++){
		if (selected[i] == 1){ continue; }
		picked.push_back(i);
		selected[i] = 1;
		pick(n, r - 1, picked, selected,food,r2,human);
		selected[i] = 0;
		picked.pop_back();
	}
}
void fastsolve(vector<vector<int> >& caneat, vector<vector<int> >& eaters, vector<int>& edible, int chosen, int& best, int& n, int& m){
	if (chosen >= best){ return; }
	int first = 0;
	while (first < n && edible[first]>0){ first++; }
	if (first == n){ best = chosen; return; }
	for (int i = 0; i < caneat[first].size(); i++){
		int food = caneat[first][i];
		for (int j = 0; j < eaters[food].size(); j++){
			edible[eaters[food][j]]++;
		}
		fastsolve(caneat, eaters, edible, chosen + 1, best, n, m);
		for (int j = 0; j < eaters[food].size(); j++){
			edible[eaters[food][j]]--;
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		map<string, int> name;
		vector<vector<int> > food;
		

		for (int i = 0; i < N; i++){
			string buf;
			cin >> buf;
			name[buf] = i;
			vector<int> vbuf;
		}

		for (int i = 0; i < M; i++){
			int n;
			cin >> n;
			vector<int> vbuf;
			food.push_back(vbuf);
			for (int j = 0; j < n; j++){
				string buf;
				cin >> buf;
				int idx = name[buf];
				food[i].push_back(idx);
			}
			//cout << i << endl;
		}

		vector<vector<int> > caneat;
		vector<vector<int> > eaters = food;
		vector<int> edible;

		int best = INF;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			caneat.push_back(vbuf);
		}
		for (int i = 0; i < M; i++){
			for (int j = 0; j < eaters[i].size(); j++){
				int value = eaters[i][j];
				caneat[value].push_back(i);
			}
		}
		
		for (int i = 0; i < N; i++){ edible.push_back(0); }
		fastsolve(caneat, eaters, edible, 0, best, N, M);
		cout << best << endl;
		/*for (int i = 1; i <= M; i++){
			int r2 = i;
			vector<int> picked;
			map<int, int> selected;
			pick(M, i, picked, selected, food, r2,N);
			//cout << i << endl;
			if (r2 == -1){ break; }
		}*/

		
	}
	system("pause");
}