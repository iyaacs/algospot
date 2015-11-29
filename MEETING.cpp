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
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<int> m;
		vector<int> f;
		for (int i = 0; i<N; i++){
			int buf;
			cin >> buf;
			m.push_back(buf);
		}
		for (int i = 0; i<N; i++){
			int buf;
			cin >> buf;
			f.push_back(buf);
		}
		sort(m.begin(), m.end());
		sort(f.begin(), f.end());
		int sum = 0;
		for (int i = 0; i<N; i++){
			int sub = m[i] - f[i];
			if (sub<0){ sub *= -1; }
			sum += sub;
		}
		cout << sum << endl;
	}

}