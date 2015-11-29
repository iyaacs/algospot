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
#define MOD 20090711
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		string str;
		cin >> str;
		string str1="";
		string str2="";
		for (int i = 0; i < str.length(); i++){
			if (i % 2 == 0){ str1.push_back(str[i]); }
			else{ str2.push_back(str[i]); }
		}
		cout << str1 << str2 << endl;
	}
}