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
#define INF 9876543210
using namespace std;
string int2bin(long long N){
	string ret = "";
	while (N != 0){
		if (N % 2 == 0){ ret = "0"+ret; }
		else{ ret = "1"+ret; }
		N /= 2;
	}
	long long len = ret.size();
	string plus = "";
	for (long long i = len; i < 32; i++){
		plus += "0";
	}
	return plus+ret;
}
string mutate(string s){
	string s1 = "";
	string s2 = "";
	string s3 = "";
	string s4 = "";
	for (int i = 0; i < 8; i++){ s1 += s[i]; }
	for (int i = 8; i < 16; i++){ s2 += s[i]; }
	for (int i = 16; i < 24; i++){ s3 += s[i]; }
	for (int i = 24; i < 32; i++){ s4 += s[i]; }
	string ret = s4 + s3 + s2 + s1;
	return ret;
}
long long bin2int(string s){
	long long ret = 0;
	for (long long i = 31; i >= 0; i--){
		if (s[i] == '1'){
			ret += pow(2, (31 - i));
		}
	}
	return ret;
}
int main(){
	long long T;
	cin >> T;
	while (T--){
		long long N;
		cin >> N;
		string s = int2bin(N);
		long long after = bin2int(mutate(s));
		cout << after << endl;
	}
	system("pause");
}