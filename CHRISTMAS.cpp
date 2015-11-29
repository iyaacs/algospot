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
#include<tr1/unordered_map>
#define INF 987654321
#define MOD 20091101
using namespace std;
using namespace tr1;
long long combi2(long long n){
	return n*(n - 1) / 2;
}
long long solve1(vector<long long>& arr){
	unordered_map<long long, long long> count;
	for (long long i = 0; i < arr.size(); i++){
		count[arr[i]]++;
	}
	unordered_map<long long, long long>::iterator it;
	long long ret = 0;
	for (it = count.begin(); it != count.end(); it++){
		if (it->second >= 2){
			//cout << it->first << " " << it->second << endl;
			ret += combi2(it->second); }
	}
	return ret;
}
long long solve2(vector<long long>& arr){
	long long N = arr.size();
	unordered_map<long long, long long> count;
	long long ret = 0;
	for (long long i = 0; i < N; i++){
		count[arr[i]]++;
		if (count[arr[i]]>1){ ret++; count.clear(); count[arr[i]]++; }
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	long long T;
	cin >> T;
	while (T--){
		long long N, K;
		cin >> N >> K;
		vector<long long> arr;
		arr.push_back(0);
		for (long long i = 1; i <= N; i++){
			long long buf;
			cin >> buf;
			buf += arr[i - 1];
			arr.push_back(buf%K);
		}

		cout << solve1(arr)%MOD <<" "<<solve2(arr)<<endl;
	}
	system("pause");
}