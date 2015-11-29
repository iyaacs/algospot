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
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;
double PI = 2.0*acos(0.0);
double polar(double x, double y){
	return PI - fmod(atan2(y, x) + 2 * PI, PI);
}
bool comp1(pair<int, double>& a, pair<int, double>& b){
	return a.second < b.second;
}
int getInvCount(vector<int>& arr, int n)
{
	int inv_count = 0;
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}
long long solve1(vector<int>& arr, vector<int>& temp, int left, int right);
long long solve2(vector<int>& arr, vector<int>& temp, int left, int mid, int right);
long long solve3(vector<int>& arr){
	int N = arr.size();
	vector<int> temp(N);
	return solve1(arr, temp, 0, N - 1);
}
long long solve1(vector<int>& arr, vector<int>& temp, int left, int right){
	int mid;
	long long invcount = 0;
	if (right > left){
		mid = (right + left) / 2;
		invcount += solve1(arr, temp, left, mid);
		invcount += solve1(arr, temp, mid + 1, right);
		invcount += solve2(arr, temp, left, mid + 1, right);
	}
	return invcount;
}

long long solve2(vector<int>& arr, vector<int>& temp, int left, int mid, int right){
	int i, j, k;
	long long inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* i is index for right subarray*/
	k = left; /* i is index for resultant merged subarray*/
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
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		double Annie, Tibber;
		scanf("%d%lf%lf", &N, &Annie, &Tibber);
		vector<pair<double, double> > star;
		vector<pair<int, double> >AnnieStar; // first : idx, last : angle
		vector<pair<int, double> > TibberStar;
		unordered_map<double, double> cache; 
		unordered_map<double, int> cache2;
		for (int i = 0; i < N; i++){
			double x, y;
			scanf("%lf%lf", &x, &y);
			AnnieStar.push_back(make_pair(i, polar(x - Annie, y)));
			cache[polar(x - Annie, y)] = polar(x - Tibber, y);
			star.push_back(make_pair(x, y));
		}
		sort(AnnieStar.begin(), AnnieStar.end(), comp1);
		for (int i = 0; i < N; i++){
			AnnieStar[i].first = i;
		}
		for (int i = 0; i < N; i++){
			cache2[AnnieStar[i].second] = AnnieStar[i].first;
		}
		for (int i = 0; i < N; i++){
			int idx = cache2[AnnieStar[i].second];
			double val = cache[AnnieStar[i].second];
			TibberStar.push_back(make_pair(idx, val));
		}
		sort(TibberStar.begin(), TibberStar.end(), comp1);
		vector<int> LAST;
		for (int i = 0; i < N; i++){
			LAST.push_back(TibberStar[i].first);
		}
		printf("%lld\n", solve3(LAST));
	}
	system("pause");
}