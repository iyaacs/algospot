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

struct RMQ{
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& arr){
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int init(const vector<int>& arr, int left, int right, int node){
		if (left == right){ return rangeMin[node] = arr[left]; }
		int mid = (left + right) / 2;
		int leftmin = init(arr, left, mid, node * 2);
		int rightmin = init(arr, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftmin, rightmin);
	}
	int query(int left, int right, int node, int nodeleft, int noderight){
		if (right < nodeleft || noderight < left){ return INF; }
		if (left <= nodeleft && noderight <= right){ return rangeMin[node]; }
		int mid = (nodeleft + noderight) / 2;
		return min(query(left, right, node * 2, nodeleft, mid), query(left, right, node * 2 + 1, mid + 1, noderight));
	}
	int update(int index, int newvalue, int node, int nodeleft, int noderight){
		if (index < nodeleft || noderight < index){ return rangeMin[node]; }
		if (nodeleft == noderight){ return rangeMin[node] = newvalue; }
		int mid = (nodeleft + noderight) / 2;
		return rangeMin[node] = min(update(index, newvalue, node * 2, nodeleft, mid), update(index, newvalue, node * 2 + 1, mid + 1, noderight));
	}
	int query(int left, int right){ return query(left, right, 1, 0, n - 1); }
	int update(int index, int newvalue){
		return update(index, newvalue, 1, 0, n - 1);
	}
};

void solve(int here, int d, vector<int>& serials, vector<int>& no2serial, vector<int>& serial2no, vector<int>& firstinserials, vector<int>& depth, vector<vector<int> >& child, int nextserial){
	no2serial[here] = nextserial;
	serial2no[nextserial] = here;
	nextserial++;
	depth[here] = d;
	firstinserials[here] = serials.size();
	serials.push_back(no2serial[here]);
	for (int i = 0; i < child[here].size(); i++){
		solve(child[here][i], d + 1, serials, no2serial, serial2no, firstinserials, depth, child, nextserial);
		serials.push_back(no2serial[here]);
	}
}

int dist(RMQ& rmq, int u, int v, vector<int>& firstinserials, vector<int>& depth, vector<int>& serial2no){
	int lu = firstinserials[u];
	int lv = firstinserials[v];
	if (lu > lv){ swap(lu, lv); }
	int lca = serial2no[rmq.query(lu, lv)];
	return depth[v] + depth[u] - (2 * depth[lca]);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N, Q;
		scanf("%d%d", &N, &Q);
		vector<vector<int> > child;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			child.push_back(vbuf);
		}
		for (int i = 1; i < N; i++){
			int c;
			scanf("%d", &c);
			child[c].push_back(i);
		}

		vector<int> serials;
		int nextserial = 0;
		vector<int> no2serial(N);
		vector<int> serial2no(N);
		vector<int> firstinserials(N);
		vector<int> depth(N);
		solve(0, 0, serials, no2serial, serial2no, firstinserials, depth, child, nextserial);

		RMQ rmq(serials);
		
		for (int i = 0; i < Q; i++){
			int a, b;
			scanf("%d%d", &a,&b);
			printf("%d\n", dist(rmq, a, b, firstinserials, depth, serial2no));
		}
	}

	system("pause");
}