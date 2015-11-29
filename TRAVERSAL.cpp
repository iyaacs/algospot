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
#define INF 9876543212
using namespace std;
vector<int> solve1(const vector<int>& v, int a, int b){
	return vector<int>(v.begin()+a,v.begin()+b);
}
void solve2(const vector<int>& pre, const vector<int>& in){
	const int N = pre.size();
	if (pre.empty()){ return; }
	const int root = pre[0];
	const int L = find(in.begin(), in.end(), root) - in.begin();
	const int R = N - 1 - L;
	solve2(solve1(pre, 1, L + 1), solve1(in, 0, L));
	solve2(solve1(pre, L + 1, N), solve1(in, L + 1, N));
	cout << root << ' ';
}
int main(){
	int C;
	cin >> C;
	while (C--){
		int n;
		cin >> n;
		vector<int> pre;
		vector<int> in;
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			pre.push_back(buf);
		}
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			in.push_back(buf);
		}
		solve2(pre, in);
		cout << endl;
	}
	system("pause");
}