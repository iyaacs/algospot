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
#define INF 1987654321
#define MOD 4294967296
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		string str;
		cin >> str;
		vector<char> ss;
		int flag = 1;
		for (int i = 0; i < str.length(); i++){
			if (str[i] == '('){ ss.push_back(str[i]); continue; }
			if (str[i] == '{'){ ss.push_back(str[i]); continue; }
			if (str[i] == '['){ ss.push_back(str[i]); continue; }
			if (ss.empty()){ flag = 0; break; }

			if (str[i] == ')' && ss.back() != '('){ flag = 0; break; }
			if (str[i] == ']' && ss.back() != '['){ flag = 0; break; }
			if (str[i] == '}' && ss.back() != '{'){ flag = 0; break; }
			if (str[i] == ')' && ss.back() == '('){ ss.pop_back(); continue; }
			if (str[i] == ']' && ss.back() == '['){ ss.pop_back(); continue; }
			if (str[i] == '}' && ss.back() == '{'){ ss.pop_back(); continue; }


		}
		if (flag == 1 && ss.empty()){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }

	}
	system("pause");
}