#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iterator>
using namespace std;

int solve(vector<int>& fence, int left, int right){
	if (left == right){ return fence[left]; }
	int mid = (left + right) / 2;
	int ret = max(solve(fence, left, mid), solve(fence, mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	int height = min(fence[lo],fence[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right){
		if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])){ hi++; height = min(height, fence[hi]); }
		else{
			lo--; height = min(height, fence[lo]);
		}
		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}

int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int testcase;
		cin >> testcase;
		vector<int> fence;
		for (int i = 0; i < testcase; i++){
			int buf;
			cin >> buf;
			fence.push_back(buf);
		}
		cout << solve(fence,0,fence.size()-1) << endl;
	}
	system("pause");
}