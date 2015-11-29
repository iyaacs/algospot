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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 987654321
#define MOD 1000000007
using namespace std;
vector<int> getdiv(int N){
	vector<int> ret;
	ret.push_back(1);
	bool flag = false;
	int sq = sqrt(N);
	if (N == sq*sq){ flag = true; }
	for (int i = 2; i < sq; i++){
		if (N%i == 0){ ret.push_back(i); ret.push_back(N/i); }
	}
	if (flag){ ret.push_back(sq); }
	return ret;
}
// int w[] = {...}; // input set  
// int x[] = {0,};  
// sumOfSubsets(size-1, sumOf(w), N);  
bool sumOfSubsets(int index, int sum, int N, vector<int>& w, vector<int>& x) {
	if (sum == N) return true;
	if (sum < N || N < 0) return false;

	//x[i+1] = 1;  
	if (sumOfSubsets(index - 1, sum - w[index], N - w[index],w,x)) {
		return true;
	}
	//x[i+1] = 0;  
	return (sumOfSubsets(index - 1, sum - w[index], N,w,x));
}
bool solve(int N, vector<int>& w){
	int ssum = 0;
	for (int i = 0; i < w.size(); i++){
		ssum += w[i];
	}
	if (ssum <= N){ return false; }
	else{
		vector<int> x(10000, 0);
		bool flag=sumOfSubsets(w.size() - 1, ssum, N, w, x);
		if (flag){ return false; }
	}
	return true;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<int> ret = getdiv(N);
		sort(ret.begin(), ret.end());

		if (solve(N,ret)){ cout << "weird" << endl; }
		else{ cout << "not weird" << endl; }
	}
	system("pause");
}
