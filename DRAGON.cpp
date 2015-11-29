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
void solve1(const string& str, int n){
	if (n == 0){ cout << str; return; }
	for (int i = 0; i < str.size(); i++){
		if (str[i] == 'X'){ solve1("X-YF",n-1); }
		else if (str[i] == 'Y'){ solve1("FX-Y",n-1); }
		else{ cout << str[i]; }
	}
}
char solve2(const string& str, vector<long long>& ds, int n, int skip){
	if (n == 0){
		assert(skip < str.size());
		return str[skip];
	}
	for (int i = 0; i < str.size(); i++){
		if (str[i] == 'X' || str[i] == 'Y'){
			if (skip >= ds[n]){ skip -= ds[n]; }
			else{
				if (str[i] == 'X'){ return solve2("X+YF", ds, n - 1, skip); }
				else{ return solve2("FX-Y", ds, n - 1, skip); }
			}
		}
		else if (skip > 0){ skip--; }
		else{ return str[i]; }
	}
	return 'a';
}
int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<long long> lendragon;
	lendragon.push_back(1);
	for (int i = 1; i <= 50; i++){
		lendragon.push_back((lendragon[i-1]*2)+2);
	}

	while (T--){
		int n, p, l;
		cin >> n >> p >> l;
		p--;
		for (int i = p; i < p + l; i++){
			cout << solve2("FX", lendragon, n, i);
		}
		cout << endl;
	}

	system("pause");
}