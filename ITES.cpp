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
#define MOD 4294967296
using namespace std;
class GEN{
public:
	unsigned int ret;
	GEN(){ ret = 1983; }
	unsigned int get(){ return ret; }
	unsigned int next(){
		ret = (ret * 214013 + 2531011) % MOD;
		return ret;
	}
};
unsigned int solve(unsigned int C, unsigned int N){
	GEN gen;
	queue<unsigned int> q;
	unsigned int sum = 0;
	unsigned int ret = 0;
	unsigned int value = gen.get() + 1;
	q.push(value);
	sum += value;
	for (unsigned int i = 0; i < N - 1; i++){
		value = (gen.next() % 10000) + 1;
		sum += value;
		//cout << value << " " << sum << endl;
		q.push(value);
		while (true){
			if (sum <= C){ break; }
			sum -= q.front();
			q.pop();
		}
		if (sum == C){ ret++; }
	}
	return ret;
}
int main(){
std::ios::sync_with_stdio(false);
unsigned int T;
cin >> T;
while (T--){
	unsigned int C, N;
	cin >> C >> N;
	cout << solve(C, N) << endl;
}

system("pause");
}