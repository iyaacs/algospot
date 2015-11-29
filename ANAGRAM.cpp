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
int main(){
	int C;
	cin >> C;
	while (C--){
		string a, b;
		cin >> a >> b;
		if (a.length() != b.length()){ cout << "No." << endl; continue; }
		if (a == b){ cout << "No." << endl; continue; }
		vector<int> arr1;
		vector<int> arr2;
		for (int i = 0; i < 128; i++){ arr1.push_back(0); arr2.push_back(0); }
		for (int i = 0; i < a.length(); i++){
			arr1[a[i]]++; arr2[b[i]]++;
		}
		int flag = 0;
		for (int i = 0; i < 128; i++){
			if (arr1[i] != arr2[i]){ flag = 1; break; }
		}
		if (flag == 0){ cout << "Yes" << endl; }
		else{ cout << "No." << endl; }
	}
	system("pause");
}