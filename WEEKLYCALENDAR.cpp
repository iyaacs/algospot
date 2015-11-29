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
#define INF 1987654321;
using namespace std;
map<string, int> cache;
int getendday(int m){
	if (m == 0){ return 31; }
	if (m == 13){ return 31; }
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){ return 31; }
	else if (m == 4 || m == 6 || m == 9 || m == 11){ return 30; }
	else{ return 28; }
}
int getrealday(int m, int d){
	int endday = getendday(m);
	if (d > 0 && d <= endday){ return d; }
	if (d <= 0){
		int endday2 = getendday(m - 1);
		return endday2 + d;
	}
	if (d > endday){
		int endday2 = getendday(m + 1);
		return d - endday;
	}
}
void solve(int m, int d, string s){
	int now = cache[s];
	vector<int> ret(7, 0);
	for (int i = 0; i < now; i++){
		ret[i] = getrealday(m,d - now + i);
	}
	for (int i = now + 1; i < 7; i++){
		ret[i] = getrealday(m, d - now + i);
	}
	ret[now] = d;
	for (int i = 0; i < 7; i++){
		cout << ret[i] << " ";
	}
	cout << endl;
}

int main(){
	cache["Sunday"] = 0;
	cache["Monday"] = 1;
	cache["Tuesday"] = 2;
	cache["Wednesday"] = 3;
	cache["Thursday"] = 4;
	cache["Friday"] = 5;
	cache["Saturday"] = 6;

	int T;
	cin >> T;
	while (T--){
		int m, d;
		string s;
		cin >> m >> d >> s;
		solve(m, d, s);
	}
	system("pause");
}