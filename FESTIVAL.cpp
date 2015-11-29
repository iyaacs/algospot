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
#include<iomanip>
#include<limits>
#define INF 987654321
using namespace std;

int main(){
	double T;
	cin >> T;
	while (T--){
		double N, L;
		cin >> N >> L;
		vector<vector<double> > num;
		vector<double> ret;
		for (double i = N; i>0; i--){
			vector<double> buf;
			//for (double j = 0; j < i; j++){ buf.push_back(0); }
			num.push_back(buf);
		}
		for (double i = 0; i < N; i++){
			double buf;
			cin >> buf;
			for (double j = 0; j <= i; j++){
				num[j].push_back(buf);
			}
		}
		for (double i = 0; i < N; i++){
			for (double j = 0; j < num[i].size()-1; j++){
				num[i][j + 1] += num[i][j];
			}
		}

		for (double i = 0; i < N; i++){
			for (double j = 0; j < num[i].size(); j++){
				int ll = j + 1;
				if (ll < L){ continue; }
				else{ ret.push_back(num[i][j] / (j + 1)); }
			}
		}
		sort(ret.begin(), ret.end());
		printf("%.11f\n",ret[0]);
	}

	system("pause");
}