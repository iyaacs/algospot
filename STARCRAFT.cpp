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
#include<hash_map>
#define INF 1987654321
#define MOD 1000000007
using namespace std;
double solve(double K, double win, double lose, double rate, double winrate){
	//if (win == K){ return 1; }
	//if (lose == K){ return 1; }
	//double ret = 0;
	//ret += (solve(K, win + 1, lose) + solve(K, win, lose + 1));
	//return ret;
	//cout << K << " " << win << " " << lose << " " << rate << " " << winrate << endl;
	//printf("K : %.3lf, WIN : %.3lf, LOSE : %.3lf, RATE : %.3lf, winrate : %.3lf\n",K,win,lose,rate,winrate);
	if (win == K){ return rate; }
	if (lose == K){ return 0; }
	double ret = 1;
	ret *= (solve(K, win + 1, lose, rate*winrate, winrate) + (solve(K, win, lose+1, rate*(1-winrate), winrate)));
	return ret;
}
int main(){
	double T;
	cin >> T;
	while (T--){
		double P, K;
		cin >> P >> K;
		P /= 100;
		double ans = solve(K, 0, 0, 1, P);
		ans *= 100;
		ans = floor(ans + 0.5);
		int ans2 = ans;
		cout << ans2 << endl;
		//cout << solve(K, 0, 0,1,P) << endl;
	}
	system("pause");
}