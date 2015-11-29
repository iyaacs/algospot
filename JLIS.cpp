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
#include<iomanip>
#include<limits>
#define INF 987654321
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

long long solve(vector<long long>& A, vector<long long>& B, long long n, long long m){
	if (n == A.size()){ return 0; }
	if (m == B.size()){ return 0; }
	long long ret = 2;
	long long vala = A[n];
	long long valb = B[m];
	long long val = max(vala, valb);
	for (long long i = n + 1; i < A.size(); i++){
		if (val < A[i]){ ret = max(ret, solve(A, B, i, m)+1); }
	}
	for (long long i = m + 1; i < B.size(); i++){
		if (val < B[i]){ ret = max(ret,solve(A,B,n,i)+1); }
	}
	return ret;
}
long long solve2(vector<long long >& A, vector<long long>& B, long long n, long long m, map<long long, map<long long,long long> >& cache){
	long long& ret = cache[n][m];
	if (ret != 0){ return ret; }
	ret = 2;
	long long a, b;
	if (n == -1){ a = NEGINF; }
	else{ a = A[n]; }
	if (m == -1){ b = NEGINF; }
	else{ b = B[m]; }
	
	long long maxval = max(a, b);
	for (long long i = n + 1; i < A.size(); i++){
		if (maxval < A[i]){
			ret = max(ret,solve2(A,B,i,m,cache)+1);
		}
	}
	for (long long i = m + 1; i < B.size(); i++){
		if (maxval < B[i]){
			ret = max(ret,solve2(A,B,n,i,cache)+1);
		}
	}
	return ret;
}
int main(){
	long long C;
	cin >> C;
	while (C--){
		long long n, m;
		cin >> n >> m;
		vector<long long> A, B;
		map<long long, map<long long, long long> > cache;
		for (long long i = 0; i < n; i++){
			long long buf;
			cin >> buf;
			A.push_back(buf);
		}
		for (long long i = 0; i < m; i++){
			long long buf;
			cin >> buf;
			B.push_back(buf);
		}
		long long ret = solve2(A, B, -1, -1,cache);
		cout << ret-2 << endl;
	}
	system("pause");
}