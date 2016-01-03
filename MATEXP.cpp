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
#include<stack>
#define INF 987654321
using namespace std;
vector<vector<int> >mulxp(vector<vector<int> >& A, vector<vector<int> >& B){
	vector<vector<int> > ret = A;
	int N = A.size();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			ret[i][j] = 0;
		}
	}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					ret[i][j] += A[i][k] * B[k][j];
					ret[i][j] %= 10007;
				}
			}
		}
	
	return ret;
}
vector<vector<int> > solve(vector<vector<int> >& A, int P){
	int N = A.size();
	if (P == 0){
		vector<vector<int> > ret(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++){ ret[i][i] = 1; }
		return ret;
	}
	if (P % 2 != 0){ 
		vector<vector<int> > buf = solve(A, P - 1);
		return mulxp(buf,A); 
	}
	vector<vector<int> > half = solve(A, P / 2);
	return mulxp(half, half);
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N, P;
		cin >> N >> P;
		vector<vector<int> > mat;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < N; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			mat.push_back(vbuf);
		}
		vector<vector<int> > ret = solve(mat, P);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cout << ret[i][j] << " ";
			}
			cout << endl;
		}
	}
	system("pause");
}