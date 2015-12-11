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

double solve(string& S, double M, double D)
{
	int N = S.size();
	double M1, M2, cost = 0;
	M2 = M;
	M1 = M2;
	for (int i = 0; i<N - 1; i++) {
		M1 *= (100.0 - D);
		M1 /= (100.0);
		if (S[i] == 'C')
		{
			cost += (M2 - M1);
		}
		M2 = M1;
	}
	if (S[N - 1] == 'C')
	{
		cost += M2;
	}
	return cost*10000.0;
}
int main()
{
	int T;
	cin >> T;
	while (T--){
		double M, D;
		cin >> M >> D;
		string S;
		cin >> S;
		double cost = solve(S, M, D);

		printf("%.1f\n", cost);
	}
	system("pause");
}