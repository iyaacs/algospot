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
#include<stack>
#define INF 987654321
using namespace std;
string L = "({[<";
string R = ")}]>";
int main(){
	int T;
	cin >> T;
	while (T--){
		string a, b;
		cin >> a >> b;
		int left = 0;
		for (int i = 0; i < b.size(); i++){
			for (int j = 0; j < b.size(); j++){
				if (b[i] == L[j]) {
					swap(L[i], L[j]);
					swap(R[i], R[j]);
				}
			}
		}
		vector<int> stk;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == L[0] || a[i] == L[1] || a[i] == L[2]|| a[i] == L[3]) {
				stk.push_back(i);
			}
			else {
				left = stk.back();
				stk.pop_back();
				if (!((abs(a[i] - a[left])) < 3)) {
					for (int j = 0; j < 4; j++) {
						if (a[i] == R[j] || a[left] == L[j]) {
							a[i] = R[j];
							a[left] = L[j];
							break;
						}
					}
				}
			}
		}
		cout << a << endl;
	}
	system("pause");
}