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
#define INF 987654321
#define MOD 1000000007
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<double> score;
		for (int i = 0; i < N; i++){
			double buf;
			cin >> buf;
			score.push_back(buf);
		}
		sort(score.begin(), score.end());
		double ret = -10000;
		int mid = score.size() / 2;
		if (score.size() % 2 == 0){
			for (int i = 0; i <mid; i++){
				int first = i;
				int second = score.size() - i-1;
				//cout << score[first] << " " << score[second] << endl;
				double midscore = score[first] + score[second];
				midscore /= 2.0;
				ret = max(ret, midscore);
			}
		}
		else{
			for (int i = 0; i <=mid; i++){
				int first = i;
				int second = score.size() - i - 1;

				//cout << score[first] << " " << score[second] << endl;
				double midscore = score[first] + score[second];
				midscore /= 2.0;
				ret = max(ret, midscore);
			}
		}
		printf("%.1lf\n", ret);

	}
	system("pause");
}