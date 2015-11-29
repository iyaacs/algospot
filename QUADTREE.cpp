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
string solve(string::iterator& it){
	char head = *it;
	it++;
	if (head == 'b' || head == 'w'){ return string(1, head); }
	string upleft = solve(it);
	string upright = solve(it);
	string lowleft = solve(it);
	string lowright = solve(it);
	return string("x") + lowleft + lowright + upleft + upright;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		string str;
		cin >> str;
		string::iterator it;
		it = str.begin();
		cout << solve(it) << endl;
	}
	system("pause");
}