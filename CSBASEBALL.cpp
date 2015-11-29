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
#include<hash_map>
#define INF 1987654321
#define MOD 1000000007
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int A, B;
		//cin >> A >> B;
		scanf("%d%d", &A, &B);
		int ans = 0;
		if (A > B){ ans = 0; }
		else{
			ans = (B - (A - 4));
		}
		//cout << ans << endl;
		printf("%d\n", ans);
	}
	system("pause");
}