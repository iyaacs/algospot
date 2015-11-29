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
using namespace std;

int main(){
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		vector<pair<int, int>> box;
		vector<int> fire;
		vector<int> eat;
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			fire.push_back(buf);
		}
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			eat.push_back(buf);
		}
		for (int i = 0; i < n; i++){
			pair<int, int> pbuf;
			pbuf.first = eat[i];
			pbuf.second = fire[i];
			box.push_back(pbuf);
		}
		sort(box.begin(), box.end());
		int sumtime = 0; 
		int ret = 0;
		//first : eat, second : fire

		for (int i = n-1; i >= 0; i--){
			sumtime += box[i].second;
			for (int j = n - 1; j > i; j--){
				box[j].first -= box[i].second;
			}
		}
		for (int i = 0; i < n; i++){
			ret += box[i].second;
		}
		sort(box.begin(), box.end());
		ret += box[n - 1].first;
		cout << ret << endl;
	}
	system("pause");
}