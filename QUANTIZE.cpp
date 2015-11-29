#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iterator>
#include<time.h>
#define INF 1987654321
using namespace std;
int cache[101][11];
void init(){
	memset(cache,-1,sizeof(cache));
}
int quantize(vector<int>& arr, int from, int partsize){
	double davg = 0;
	for (int i = from; i<from + partsize; i++){
		davg += arr[i];
	}
	davg /= (double)partsize;
	int iavg = (int)davg;
	int avg;
	double cha = davg - iavg;
	if (cha >= 0.5){ avg = iavg + 1; }
	else{ avg = iavg; }
	int ret = 0;
	for (int i = from; i<from + partsize; i++){
		ret += (arr[i] - avg)*(arr[i] - avg);
	}
	return ret;
}

int solve(vector<int>& arr, int from, int parts)
{
	if (from == arr.size()){ return 0; } // 시작점이 끝까지 왔을때 (모든 숫자 양자화 완료) -> return 0
	if (parts == 0){ return INF; } // from이 끝까지 안갔는데, 모든 숫자를 다 양자화해버렸을때 -> 더이상 양자화할수없을때 -> 매우 큰 수 반환
	int& ret = cache[from][parts];
	if (ret != -1){ return ret; }
	ret = INF;
	for (int partsize = 1; from + partsize <= arr.size(); partsize++){
		ret = min(ret, quantize(arr, from, partsize) + solve(arr, from + partsize, parts - 1));
	}
	return ret;


}
int main(){
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--){
		int n, quant;
		cin >> n >> quant;
		vector<int> arr;
		init();
		for (int i = 0; i<n; i++){
			int buf;
			cin >> buf;
			arr.push_back(buf);
		}

		sort(arr.begin(), arr.end());
		cout << solve(arr, 0, quant) << endl;
	}
	system("pause");
}