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
		int n;
		int sumplus = 0;
		int sumany = 0;
		int max = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			int num;
			cin >> num;
			if (sumplus + num >= sumplus){ sumplus += num; }
			else{ sumplus = 0; }
			if (sumany + num >= 0){ sumany += num; }
			else{ sumany = 0; }

			if (sumplus > sumany){
				if (sumplus > max){ max = sumplus; }
			}
			else{
				if (sumany > max){ max = sumany; }
			}
		}
		cout << max << endl;
	}
	system("pause");
}