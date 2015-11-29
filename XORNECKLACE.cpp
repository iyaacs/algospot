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
using namespace std;

/*void pick(long long n, long long k, vector<long long>& picked, map<long long, long long>& selected, vector<long long>& beads, long long& mmax){
	if (k == 0){
		long long psum = 0;
		for (long long i = 0; i < picked.size()-1; i++){
			long long a = beads[picked[i]];
			long long b = beads[picked[(i + 1)]];
			psum += (a^b);
		}
		long long a = beads[picked[0]];
		long long b = beads[picked[picked.size()-1]];
		psum += (a^b);
		if (psum > mmax){ mmax = psum; }
	}
	long long smallest = -1;
	if (picked.size() == 0){ smallest = 0; }
	else{ smallest = picked.back(); }
	for (long long i = smallest; i < n; i++){
		if (selected[i] == 1){ continue; }
		picked.push_back(i);
		selected[i] = 1;
		pick(n, k - 1, picked, selected,beads,mmax);
		selected[i] = 0;
		picked.pop_back();
	}
}*/

long long pick(vector<long long>& beads){
	long long sum = 0;
	for (long long i = 0; i < beads.size()-1; i++){
		sum += beads[i] ^ beads[i + 1];
	}
	sum += beads[0] ^ beads[beads.size() - 1];
	return sum;
}

int main(){
	long long T;
	cin >> T;
	while (T--){
		long long N;
		cin >> N;
		vector<long long> beads;
		for (long long i = 0; i < N; i++){
			long long buf;
			cin >> buf;
			beads.push_back(buf);
		}
		cout << pick(beads) << endl;
	}
	system("pause");
}