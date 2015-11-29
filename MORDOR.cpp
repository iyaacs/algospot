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

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, Q;
		cin >> N >> Q;
		vector<int> arr;
		vector<int> marr;
		for (int i = 0; i < N; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
			marr.push_back(-buf);
		}
		RMQ rmq(arr);
		RMQ mrmq(marr);
		for (int i = 0; i < Q; i++){
			int start;
			int end;
			cin >> start >> end;
			int mmin = rmq.query(start, end);
			int mmax = mrmq.query(start, end);
			mmax *= (-1);
			cout << mmax - mmin << endl;
		}

	}
system("pause");
}