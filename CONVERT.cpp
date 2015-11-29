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
#define INF 987654321
using namespace std;
int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++){
		double a;
		string b;
		cin >> a >> b;
		double c;
		string d;
		if (b == "kg"){ d = "lb";	 c = a*2.2046;	 }
		if (b == "l"){ d = "g"; c = a*0.2642;	 }
		if (b == "lb"){ d = "kg"; c = a * 0.4536; }
		if (b == "g"){ d = "l"; c = a * 3.7854; }
		cout << i << " ";
		printf("%.4lf ", c);
		cout << d << endl;
	}
	system("pause");
}