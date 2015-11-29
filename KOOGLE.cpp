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
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		map<string, long double> arr;
		for (int i = 0; i < N; i++){
			string buf;
			long double logvalue;
			cin >> buf;
			int num = 0;
			int alpha = 0;
			for (int i = 0; i < buf.length(); i++){
				if (buf[i] < 97){ num++; }
				else{ alpha++; }
			}
			logvalue = (log(26)*alpha) + (log(10)*num);
			arr[buf] = -logvalue;
		}
		map<string, long double>::iterator it;
		long double mmin = INF;
		string ans = "";
		for (it = arr.begin(); it != arr.end(); it++){
			if (mmin>it->second){ mmin = it->second; ans = it->first; }
		}
		cout << ans << endl;

		
	}
	system("pause");
}