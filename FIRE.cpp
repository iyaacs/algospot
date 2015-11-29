#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<queue>
#include<deque>
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
		return min(query(left,right,node*2,nodeleft,mid), query(left,right,node*2+1,mid+1,noderight));
	}
	int update(int index, int newvalue, int node, int nodeleft, int noderight){
		if (index < nodeleft || noderight < index){ return rangeMin[node]; }
		if (nodeleft == noderight){ return rangeMin[node] = newvalue; }
		int mid = (nodeleft + noderight) / 2;
		return rangeMin[node] = min(update(index,newvalue,node*2,nodeleft,mid),update(index,newvalue,node*2+1,mid+1,noderight));
	}
	int query(int left, int right){ return query(left,right,1,0,n-1); }
	int update(int index, int newvalue){
		return update(index, newvalue, 1, 0, n - 1);
	}
};
void solve4(RMQ& rmq, vector<int>& FIRE, int N, int P){
	for (int i = P; i < N; i++){
		int start = i - P;
		int end = i - 1;
		FIRE[i] += rmq.query(start, end);
		rmq.update(i, FIRE[i]);
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N, P;
		scanf("%d%d", &N, &P);
		vector<int> FIRE;
		for (int i = 0; i < N; i++){
			int fire;
			scanf("%d", &fire);
			FIRE.push_back(fire);
		}
		RMQ rmq(FIRE);
		solve4(rmq, FIRE, FIRE.size(), P);
		int ret = rmq.query(N - P, N - 1);
		printf("%d\n", ret);
	}
}