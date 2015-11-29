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
int T;
cin >> T;
while (T--){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int a, b;
	cin >> a >> b;
	int small = a;
	char smallchar = 'a';
	if (small > b){ small = b; smallchar = 'b'; }
	int sum = 0;
	if (n==1&&str[0]=='?'){ sum += small; str[0] = smallchar; }
	if (n % 2 == 0){
		for (int i = 0; i < n / 2; i++){
			if (str[i] == '?' && str[n - 1 - i] == 'a'){ str[i] = 'a'; sum += a; continue; }
			if (str[i] == '?' && str[n - 1 - i] == 'b'){ str[i] = 'b'; sum += b; continue; }
			if (str[i] == 'a' && str[n - 1 - i] == '?'){ str[n - 1 - i] = 'a'; sum += a; continue; }
			if (str[i] == 'b' && str[n - 1 - i] == '?'){ str[n - 1 - i] = 'b'; sum += b; continue; }
			if (str[i] == '?' && str[n - 1 - i] == '?'){ str[i] = smallchar; str[n - 1 - i] = smallchar; sum += (small * 2); continue; }
		}
	}
	else{
		for (int i = 0; i < n / 2; i++){
			if (str[i] == '?' && str[n - 1 - i] == 'a'){ str[i] = 'a'; sum += a; continue; }
			if (str[i] == '?' && str[n - 1 - i] == 'b'){ str[i] = 'b'; sum += b; continue; }
			if (str[i] == 'a' && str[n - 1 - i] == '?'){ str[n - 1 - i] = 'a'; sum += a; continue; }
			if (str[i] == 'b' && str[n - 1 - i] == '?'){ str[n - 1 - i] = 'b'; sum += b; continue; }
			if (str[i] == '?' && str[n - 1 - i] == '?'){ str[i] = smallchar; str[n - 1 - i] = smallchar; sum += (small * 2); continue; }
		}
		if (str[(n / 2)] == '?'){ str[(n / 2)] = smallchar; sum += small; }
	}
	cout << sum << endl;
}
system("pause");
}