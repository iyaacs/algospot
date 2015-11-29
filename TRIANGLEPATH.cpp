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
using namespace std;
int solve(vector<vector<int> >& v, int floor, int index, int sum){
	int ret = 0;
	if (floor+1 > v.size()){ return ret+sum; }
	if (index > v[floor].size()){ return ret; }
	sum += v[floor][index];
	return ret = max(solve(v,floor+1,index,sum),solve(v,floor+1,index+1,sum));
}
int solve2(vector<vector<int> >& v, int floor, int index, vector<vector<int> >& cache){
	if (floor + 1 == v.size()){ return v[floor][index]; }
	int& ret = cache[floor][index];
	if (ret != -1){ return ret; }
	return ret = max(solve2(v,floor+1,index,cache),solve2(v,floor+1,index+1,cache)) + v[floor][index];
}

int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		vector<vector<int> > triangle;
		vector<vector<int> > cache;
		for (int i = 0; i < 110; i++){
			vector<int> vcbuf;
			for (int j = 0; j < 110; j++){
				vcbuf.push_back(-1);
			}
			cache.push_back(vcbuf);
		}

		for (int i = 0; i < n; i++){
			vector<int> vbuf;
			for (int j = 0; j < i + 1; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			triangle.push_back(vbuf);
		}
		//cout << solve(triangle, 0, 0,0) << endl;
		cout << solve2(triangle, 0, 0, cache) << endl;
		///////////


	}
	system("pause");
}