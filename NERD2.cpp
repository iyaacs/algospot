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
#define INF 987654321
using namespace std;
bool solve1(map<int,int>& point, int x, int y){
	map<int, int>::iterator it;
	it = point.lower_bound(x);
	if (it == point.end()){ return false; }
	if (y >= it->second){ return false; }
	return true;
}
void solve2(map<int, int>& point, int x, int y){
	map<int, int>::iterator it;
	it = point.lower_bound(x);
	if (it == point.begin()){ return; }
	it--;
	while (1){
		if (it->second > y){ break; }
		if (it == point.begin()){
			point.erase(it);
			break;
		}
		else{
			map<int, int>::iterator it2 = it;
			it2--;
			point.erase(it);
			it = it2;
		}
	}
}
int main(){
	int C;
	cin >> C;
	while (C--){
		map<int, int> point;
		int N;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; i++){
			int x, y;
			cin >> x >> y;
			if (solve1(point, x, y)){ sum += point.size(); continue; }
			solve2(point, x, y);
			point[x] = y;
			sum += point.size();
		}
		cout << sum << endl;
	}
	system("pause");
}