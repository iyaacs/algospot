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
	ios::sync_with_stdio(false);
	while (true){
		string str;
		cin >> str;
		if (str == "end"){ break; }
		long long sum = 0;
		for (int i = 0; i < str.length(); i++){
			if ('0' <= str[i] && str[i] <= '9'){ sum += str[i] - 48; sum = sum % 61; continue; }
			if ('A' <= str[i] && str[i] <= 'Z'){ sum += str[i] - 55; sum = sum % 61; continue; }
			if ('a' <= str[i] && str[i] <= 'z'){ sum += str[i] - 61; sum = sum % 61; continue; }
		}
		if (sum % 61 == 0){ cout << "yes" << endl; }
		else{ cout << "no" << endl; }
	}
}