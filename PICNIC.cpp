#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
int friends[11][11] = { 0, };
int n = 0;
int countpair(bool taken[10]){
	int firstFree = -1;
	for (int i = 0; i < n; i++){ if (!taken[i]){ firstFree = i; break; } }
	if (firstFree == -1){ return 1; }
	int ret = 0;
	for (int pairwith = firstFree + 1; pairwith < n; pairwith++){
		if (!taken[pairwith]&&friends[firstFree][pairwith]){
			taken[firstFree] = taken[pairwith] = true;
			ret += countpair(taken);
			taken[firstFree] = taken[pairwith] = false;
		} 
	
	}
	return ret;
}
void init(){
	n = 0;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){ friends[i][j] = 0; }
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	//////////
	int T;
	cin >> T;
	while (T--){
		init();
		int human;
		int pair;
		bool taken[10] = { 0, };
		cin >> human >> pair;
		n = human;
		for (int i = 0; i < pair; i++){
			int left, right;
			cin >> left >> right;
			if (right < left){ swap(right, left); }
			friends[left][right] = 1;
		}

		cout << countpair(taken) << endl;
	}
	//////////
	system("pause");
}