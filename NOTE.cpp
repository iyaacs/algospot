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
int main(){
	vector<int> arr;
	for (int i = 0; i < 8; i++){
		int buf;
		cin >> buf;
		arr.push_back(buf);
	}
	bool asc = 0;
	bool desc = 0;
	for (int i = 0; i < 7; i++){
		if (arr[i + 1] - arr[i] > 0){ asc = 1; }
		else if (arr[i + 1] - arr[i] < 0){ desc = 1; }
		else{ asc = 1; desc = 1; break; }
	}
	if (asc == 1 && desc == 1){ cout << "mixed" << endl; }
	if (asc == 1 && desc == 0){ cout << "ascending" << endl; }
	if (asc == 0 && desc == 1){ cout << "descending" << endl; }
	system("pause");
}