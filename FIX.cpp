#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	while (testcase--){
		int i, j, k, l;
		int T;
		int judge = 0;
		cin >> T;
		for (i = 1; i <= T; i++){
			int buf;
			cin >> buf;
			if (buf == i){ judge++; }
		}
		cout << judge << endl;
	}
}