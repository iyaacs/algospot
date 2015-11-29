#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;
long long calcgcd(long long a, long long b) {
	while (b != 0) {
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}
int main(){
	long long T;
	scanf("%lld",&T);
	while (T--){
		long long N;
		cin >> N;
		vector<pair<long long, long long> > stone;
		for (long long i = 0; i < N; i++){
			long long x, y;
			scanf("%lld%lld",&x,&y);
			stone.push_back(make_pair(x, y));
		}
		sort(stone.begin(), stone.end());
		int ret = 0;
		for (long long i = 0; i < N; i++){

			unordered_map<long long, long long> cache;
			for (long long j = i+1; j < N; j++){
				long long x1 = stone[i].first;
				long long y1 = stone[i].second;
				long long x2 = stone[j].first;
				long long y2 = stone[j].second;
				long long A = y2 - y1;
				long long B = x1 - x2;
				long long C = (x2 - x1)*y1 - (y2 - y1)*x1;
				long long gcd = calcgcd(A, calcgcd(B, C));
				A /= gcd;
				B /= gcd;
				C /= gcd;
				long long Q = A*pow(20000, 2) + B * 20000 + C;
				cache[Q]++;
			}
			unordered_map<long long, long long>::iterator it;
			for (it = cache.begin(); it != cache.end(); it++){
				if (it->second == 4){ ret++; }
			}
			
		}
		printf("%d\n",ret);
	}
}