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
#include <limits>
#include <cstddef>
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
using namespace std;
using namespace tr1;
const long long INF = numeric_limits<long long>::max();
class RMQ{
public:
	long long n;
	vector<long long> rangeMin;
	RMQ(const vector<long long>& arr){
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	long long init(const vector<long long>& arr, long long left, long long right, long long node){
		if (left == right){ return rangeMin[node] = arr[left]; }
		long long mid = (left + right) / 2;
		long long leftmin = init(arr, left, mid, node * 2);
		long long rightmin = init(arr, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftmin, rightmin);
	}
	long long query(long long left, long long right, long long node, long long nodeleft, long long noderight){
		if (right < nodeleft || noderight < left){ return INF; }
		if (left <= nodeleft && noderight <= right){ return rangeMin[node]; }
		long long mid = (nodeleft + noderight) / 2;
		return min(query(left, right, node * 2, nodeleft, mid), query(left, right, node * 2 + 1, mid + 1, noderight));
	}
	long long update(long long index, long long newvalue, long long node, long long nodeleft, long long noderight){
		if (index < nodeleft || noderight < index){ return rangeMin[node]; }
		if (nodeleft == noderight){ return rangeMin[node] = newvalue; }
		long long mid = (nodeleft + noderight) / 2;
		return rangeMin[node] = min(update(index, newvalue, node * 2, nodeleft, mid), update(index, newvalue, node * 2 + 1, mid + 1, noderight));
	}
	long long query(long long left, long long right){ return query(left, right, 1, 0, n - 1); }
	long long update(long long index, long long newvalue){
		return update(index, newvalue, 1, 0, n - 1);
	}
};
vector<long long> arrminus(vector<long long>& arr){
	vector<long long> ret;
	for (long long i = 0; i < arr.size(); i++){
		ret.push_back(-arr[i]);
	}
	return ret;
}

long long solve1(vector<long long>& arr, vector<long long>& temp, long long left, long long right);
long long solve2(vector<long long>& arr, vector<long long>& temp, long long left, long long mid, long long right);
long long solve3(vector<long long>& arr){
	long long N = arr.size();
	vector<long long> temp(N);
	return solve1(arr, temp, 0, N - 1);
}
long long solve1(vector<long long>& arr, vector<long long>& temp, long long left, long long right){
	long long mid;
	long long invcount = 0;
	if (right > left){
		mid = (right + left) / 2;
		invcount += solve1(arr, temp, left, mid);
		invcount += solve1(arr, temp, mid + 1, right);
		invcount += solve2(arr, temp, left, mid + 1, right);
	}
	return invcount;
}

long long solve2(vector<long long>& arr, vector<long long>& temp, long long left, long long mid, long long right){
	long long i, j, k;
	long long inv_count = 0;

	i = left;
	j = mid;  
	k = left; 
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main(){
	long long T;
	scanf("%lld",&T);
	while (T--){
		long long N, M;
		scanf("%lld%lld",&N,&M);
		vector<long long> arr(N,0);
		for (long long i = 0; i < N; i++){
		    scanf("%lld",&arr[i]);
		}
		vector<long long> arr2 = arr;
		vector<long long> minusarr = arrminus(arr);
		RMQ rmq(arr);
		RMQ minusrmq(minusarr);
		unordered_map<long long, long long> n2id;
		for (long long i = 0; i < arr.size(); i++){
			n2id[arr[i]] = i;
		}
		long long ret = solve3(arr);
		long long printval = ret;
		for (long long i = 0; i < M; i++){
			long long a, b;
			scanf("%lld%lld",&a,&b);
			if (a == b){ continue; }
			a--; b--;
			long long minval = rmq.query(a, b);
			long long maxval = -minusrmq.query(a, b);
			long long minidx = n2id[minval];
			long long maxidx = n2id[maxval];
			if (minidx == maxidx){ continue; }
			if (minidx < maxidx){
				long long pv = (2 * (maxidx - minidx) - 1);
				ret += pv;
				printval += ret;
				swap(n2id[minval], n2id[maxval]);
				rmq.update(minidx, maxval);
				rmq.update(maxidx, minval);
				minusrmq.update(minidx, -maxval);
				minusrmq.update(maxidx, -minval);
			}
			if (minidx > maxidx){
				long long pv=(2 * (maxidx - minidx) + 1);
				ret += pv;
				printval += ret;
				swap(n2id[minval], n2id[maxval]);
				rmq.update(minidx, maxval);
				rmq.update(maxidx, minval);
				minusrmq.update(minidx, -maxval);
				minusrmq.update(maxidx, -minval);
			}
		}
		printf("%lld\n",printval);
	}

	system("pause");
}