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
#define MAX 1987654321;

int classify(string& str, int start, int sub){
	string S = str.substr(start, sub);
	if (S == string(S.size(), S[0])){
		return 1;
	}
	bool flagdc = 1;
	for (int i = 0; i < S.size() - 1; i++){
		if (S[i + 1] - S[i] != S[1] - S[0]){ flagdc = 0; break; }
	}
	if (flagdc == true && (S[1] - S[0] == 1 || S[1] - S[0] == -1)){ return 2; }

	bool tictoc = 1;
	for (int i = 0; i < S.size(); i++){
		if (S[i] != S[i % 2]){ tictoc = 0; break; }
	}
	if (tictoc){ return 4; }
	if (flagdc){ return 5; }
	return 10;
}

int solve(string& str, vector<int>& cache, int start){
	if (start == str.size()){ return 0; }
	int& ret = cache[start];
	if (ret != -1){ return ret; }
	ret = MAX;
	for (int i = 3; i <= 5; i++){
		if (start + i <= str.size()){
			ret = min(ret, solve(str, cache, start + i) + classify(str, start,i));
		}
	}
	return ret;
}
int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		string str;
		vector<int> cache;
		for (int i = 0; i < 10010; i++){
			cache.push_back(-1);
		}
		cin >> str;
		cout << solve(str, cache, 0) << endl;
	}
	system("pause");
}