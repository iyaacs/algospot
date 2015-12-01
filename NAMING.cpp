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

vector<int> solve(string& str){
	int n = str.size();
	vector<int> ret(n, 0);
	int begin = 1;
	int matched = 0;
	while (begin + matched < n){
		if (str[begin + matched] == str[matched]){ matched++; ret[begin + matched - 1] = matched; }
		else{
			if (matched == 0){ begin++; }
			else{
				begin += matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}
void solve2(string& str){
	vector<int> cache = solve(str);
	int n = str.size();
	stack<int> ret;
	while (n>0){
		ret.push(n);
		n = cache[n - 1];
	}
	while (!ret.empty()){
		cout << ret.top() << " ";
		ret.pop();
	}
	cout << endl;
}
int main(){
	string a, b;
	cin >> a >> b;
	string s = a + b;
	solve2(s);
	system("pause");
}