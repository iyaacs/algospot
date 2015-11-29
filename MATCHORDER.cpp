#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	int C;
	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		vector<int> rus;
		vector<int> kor;
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			rus.push_back(-buf);
		}
		for (int i = 0; i < n; i++){
			int buf;
			cin >> buf;
			kor.push_back(-buf);
		}
		sort(rus.begin(), rus.end());
		sort(kor.begin(), kor.end());
		for (int i = 0; i < n; i++){ kor[i] *= (-1); rus[i] *= (-1); }
		int maxidx = 0;
		int minidx =	n - 1;
		vector<int>::iterator maxit = kor.begin();
		vector<int>::iterator minit = kor.end() - 1;
		int win = 0;
		for (int i = 0; i < n; i++){
			if (rus[i]>kor[0]){ kor.erase(minit); minit = kor.end() - 1; continue; }
			for (int j = kor.size() - 1; j >= 0; j--){
				if (rus[i] <= kor[j]){ win++; kor.erase(kor.begin() + j); minit = kor.end() - 1; break; }
			}
		}
		cout << win << endl;
		
	}
	system("pause");
}