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
int solve(vector<int>& weight, vector<int>& urgent, vector<vector<int> >& cache, int here, int able){
	int& ret = cache[here][able];
	if (ret != -1){ return ret; }
	if (here >= weight.size()){ return 0; }
	ret = solve(weight, urgent, cache,here + 1, able);
	if (able >= weight[here]){
		ret = max(ret,solve(weight,urgent,cache,here+1,able-weight[here])+urgent[here]);
	}
	return ret;
}
void remake(vector<int>& weight, vector<int>& urgent, vector<vector<int> >& cache, int here, int able, vector<int>& select){
	if (here >= weight.size()){ return; }
	if (solve(weight,urgent,cache,here,able)==solve(weight,urgent,cache,here+1,able)){
		remake(weight, urgent, cache, here + 1, able, select);
	}
	else{
		select.push_back(here);
		remake(weight,urgent,cache,here+1,able-weight[here],select);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int n, w;
		cin >> n >> w;
		vector<string> name;
		vector<int> weight;
		vector<int> urgency;
		vector<vector<int> > cache;
		vector<int> select;
		for (int i = 0; i < 101; i++){
			vector<int> vbuf;
			for (int j = 0; j < 1001; j++){
				vbuf.push_back(-1);
			}
			cache.push_back(vbuf);
		}
		for (int i = 0; i < n; i++){
			string strbuf;
			int intbuf1, intbuf2;
			cin >> strbuf >> intbuf1 >> intbuf2;
			name.push_back(strbuf);
			weight.push_back(intbuf1);
			urgency.push_back(intbuf2);
		}
		cout<<solve(weight, urgency, cache, 0, w)<<" ";
		remake(weight, urgency, cache, 0, w, select);
		cout << select.size() << endl;
		for (int i = 0; i < select.size(); i++){
			cout << name[select[i]] << endl;
		}
	}
	system("pause");
}