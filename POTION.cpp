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
using namespace std;
vector<int> solve(vector<int> R, vector<int> P){
	int N = R.size();
	vector<int> ret(N);
	int idx = 0;
	while (true){
		idx++;
		int flag = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				int req = (P[i] * R[j] + R[i] - 1) / R[i];
				if (req>P[j]){ ret[j] += req - P[j];
				P[j] = req;
				flag = 1;
				}
			}
		}
		if (flag == 0){ return ret; }
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;	
		vector<int> R;
		vector<int> P;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			R.push_back(buf);
		}
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			P.push_back(buf);
		}
		vector<int> ret = solve(R, P);
		for (int i = 0; i < ret.size(); i++){
			cout << ret[i] << " ";
		}
		cout << endl;
	}
}