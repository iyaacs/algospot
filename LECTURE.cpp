#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		string str;
		cin >> str;

		vector<string> vstr;
		int flag = 0;
		string sbuf = "";
		for (int i = 0; i<str.length(); i++){
			flag++;
			sbuf += str[i];
			if (flag == 2){ vstr.push_back(sbuf); sbuf = ""; flag = 0; }
		}
		sort(vstr.begin(), vstr.end());
		for (int i = 0; i<vstr.size(); i++){
			cout << vstr[i];

		}
		cout << endl;
	}
}