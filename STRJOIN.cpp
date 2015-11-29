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
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int n;
		vector<int> arr;
		cin >> n;
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}
		int ret = 0;
		
		while (true){
			if (arr.size() <= 2){ break; }
			int min1 = INF;
			int min2 = INF;
			int min1idx = -1;
			int min2idx = -1;	
			for (int i = 0; i < arr.size(); i++){
				if (min1>arr[i]){ min1 = arr[i]; min1idx = i; }
			}
			arr.erase(arr.begin() + min1idx);
			for (int i = 0; i < arr.size(); i++){
				if (min2>arr[i]){ min2 = arr[i]; min2idx = i; }
			}
			arr.erase(arr.begin() + min2idx);
			ret += min1;
			ret += min2;
			arr.push_back(min1 + min2);
		}
		if (arr.size() == 1){ ret += arr[0]; }
		if (arr.size() == 2){ ret += arr[0]; ret += arr[1]; }
		cout << ret << endl;
	}
	system("pause");
}