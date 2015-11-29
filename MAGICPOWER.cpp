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
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		vector<int> item;
		int max = 0;
		for (int i = 0; i < 10010; i++){ item.push_back(0); }
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			if (max < buf){ max = buf; }
			item[buf]++;
		}
		int sum = 0;
		for (int i = 0; i < M; i++){
			for (int hell = 0; hell < 1000000; hell++){
				if (max != 0){
					if (item[max]>1){ sum += max; item[max]--; item[max - 1]++; break; }
					if (item[max] == 1){ sum += max; item[max]--; item[max - 1]++;  max--; break; }
					if (item[max] == 0){ max--; }
				}
				if (max == 0){ break; }
			}
		}
		cout << sum << endl;

	}
	system("pause");
}