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
void solve(vector<string>& str, vector<int>& idx, vector<string>& out){
	string ret = "";
	for (int i = 0; i < idx.size(); i++){
		ret += str[idx[i]];
	}
	int len = ret.size();
	for (int i = 0; i <= len / 2; i++){
		int src = i;
		int dst = len - 1 - i;
		if (ret[src] != ret[dst]){ return; }
	}
	out.push_back(ret);
}

int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<string> str;
		vector<int> idx;
		for (int i = 0; i < N; i++){
			string s;
			cin >> s;
			str.push_back(s);
			idx.push_back(i);
		}
		vector<string> out;

		do{
			solve(str, idx, out);

		} while (next_permutation(idx.begin(), idx.end()));
	
		sort(out.begin(), out.end());
		cout << out[0] << endl;
	}

	system("pause");
}