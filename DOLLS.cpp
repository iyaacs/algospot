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
#define INF 1987654321
#define MOD 20090711
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		vector<pair<int, int> > dolls;
		vector<int> dollidx;
		for (int i = 0; i < N; i++){
			int buf;
			dollidx.push_back(-1);
			cin >> buf;
			dolls.push_back(make_pair(buf, i));
		}
		sort(dolls.begin(), dolls.end());
		for (int i = 0; i < N; i++){
			dollidx[dolls[i].second] = i;
		}
		int remain = M;
		int smallest = 0;
		int i;
		for (i = 0; i < N; i++){
			int n_avail = dolls[i].first - (i>0 ? dolls[i - 1].first : 0);
			int avail = n_avail * (N - i);
			if (avail > remain) break;
			smallest = dolls[i].first;
			remain -= avail;
		}
		int div = N == i ? 0 : (remain / (N - i));
		int mod = N == i ? 0 : (remain % (N - i));
		for (int j = 0; j<N; j++) {
			if (i > dollidx[j]) {
				cout << dolls[dollidx[j]].first << ' ';
			}
			else {
				cout << smallest + div + (mod-->0 ? 1 : 0) << ' ';
			}
		}
		cout << endl;
	}//end of testcase
	system("pause");
}