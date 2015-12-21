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
#define INF 987654321
using namespace std;

class mycomp{
public:
	string& s;
	mycomp(string& as) :s(as){};
	bool operator () (int a, int b){
		if (strcmp(s.c_str() + a, s.c_str() + b) < 0){ return true; }
		return false;
	}
};
vector<int> getsuffixarray(string& s){
	vector<int> arr;
	for (int i = 0; i < s.size(); i++){
		arr.push_back(i);
	}
	sort(arr.begin(), arr.end(), mycomp(s));
	return arr;
}
int commonprefix(string& s, int a, int b){
	int ret = 0;
	while ((a < s.size()) && (b < s.size()) && (s[a] == s[b])){ a++; b++; ret++; }
	return ret;
}
int solve(string& S, int K){
	vector<int> arr = getsuffixarray(S);
	int ret = 0;
	for (int i = 0; i + K <= S.size(); i++){
		ret = max(ret, commonprefix(S, arr[i], arr[i + K - 1]));
	}
	return ret;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int K;
		string S;
		cin >> K >> S;
		cout << solve(S, K) << endl;
	}
	system("pause");
}