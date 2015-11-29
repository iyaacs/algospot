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
int main(){
	int C;
	cin >> C;
	while (C--){
		int N, M;
		cin >> N >> M;
		vector<vector<pair<int, int> > >pvec;
		for (int i = 0; i < M; i++){
			vector<pair<int, int> > vpbuf;
			pvec.push_back(vpbuf);
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				int price, bonus;
				cin >> price;
				cin >> bonus;
				pvec[j].push_back(make_pair(bonus,price));
			}
		}
		for (int i = 0; i < M; i++){
			sort(pvec[i].begin(), pvec[i].end());
		}

		vector<int> ret;
		for (int j = 0; j < M; j++){
			int sum = 0;
			int currbonus = 0;
		for (int i = N-1; i >= 0; i--){
			int b = pvec[j][i].first;
			int p = pvec[j][i].second;
			//cout << "B : " << b << " , P : " << p << endl;
			if (currbonus >= p){ currbonus -= p; currbonus += b; 

			//cout << "Curr : " << currbonus << " , p : " << p << " , sum : " << sum << endl;
			continue; }
			else{ p -= currbonus; currbonus = b; sum += p; 

			//cout << "Curr : " << currbonus << " , p : " << p << " , sum : " << sum << endl;
			}
			}
	//	cout << endl;
		ret.push_back(sum);
		}
		sort(ret.begin(), ret.end());
		cout << ret[0] << endl;

	}
	system("pause");
}