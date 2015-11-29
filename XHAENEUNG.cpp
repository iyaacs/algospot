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
#include<limits>
#define INF 1987654321
using namespace std;
int main(){
	int C;
	cin >> C;
	while (C--){
		string a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int left, right;
		vector<int> sex;
		for (int i = 0; i < 128; i++){
			sex.push_back(0);
		}
		for (int i = 0; i < e.length(); i++){ sex[e[i]]++; }
		if (a == "zero"){ left = 0; }
		if (a == "one"){ left = 1; }
		if (a == "two"){ left = 2; }
		if (a == "three"){ left = 3; }
		if (a == "four"){ left = 4; }
		if (a == "five"){ left = 5; }
		if (a == "six"){ left = 6; }
		if (a == "seven"){ left = 7; }
		if (a == "eight"){ left = 8; }
		if (a == "nine"){ left = 9; }
		if (a == "ten"){ left = 10; }

		if (c == "zero"){ right = 0; }
		if (c == "one"){ right = 1; }
		if (c == "two"){ right = 2; }
		if (c == "three"){ right = 3; }
		if (c == "four"){ right = 4; }
		if (c == "five"){ right = 5; }
		if (c == "six"){ right = 6; }
		if (c == "seven"){ right = 7; }
		if (c == "eight"){ right = 8; }
		if (c == "nine"){ right = 9; }
		if (c == "ten"){ right = 10; }
		int ans;
		if (b == "+"){ ans = right + left; }
		if (b == "-"){ ans = left-right; }
		if (b == "*"){ ans = right * left; }
		if (ans < 0){ cout << "No" << endl; continue; }
		if (ans > 10){ cout << "No" << endl; continue; }
		
		if (ans == 0){
			if (sex['z'] == 1 && sex['e'] == 1 && sex['r'] == 1 && sex['o'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 1){
			if (sex['o'] == 1 && sex['n'] == 1 && sex['e'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 2){
			if (sex['t'] == 1 && sex['w'] == 1 && sex['o'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 3){
			if (sex['t'] == 1 && sex['h'] == 1 && sex['r'] == 1 && sex['e'] == 2){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 4){
			if (sex['f'] == 1 && sex['o'] == 1 && sex['u'] == 1 && sex['r'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 5){
			if (sex['f'] == 1 && sex['i'] == 1 && sex['v'] == 1 && sex['e'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 6){
			if (sex['s'] == 1 && sex['i'] == 1 && sex['x'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 7){
			if (sex['s'] == 1 && sex['e'] == 2 && sex['v'] == 1 && sex['n'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 8){
			if (sex['e'] == 1 && sex['i'] == 1 && sex['g'] == 1 && sex['h'] == 1 && sex['t'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 9){
			if (sex['n'] == 2 && sex['i'] == 1 && sex['e'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}
		if (ans == 10){
			if (sex['t'] == 1 && sex['e'] == 1 && sex['n'] == 1){ cout << "Yes" << endl; }
			else{ cout << "No" << endl; }
		}

	}
	system("pause");
}