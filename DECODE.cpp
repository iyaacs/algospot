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
vector<vector<int> > gen(int R, int C, string& S){
	vector<vector<int> > ret;
	int idx = 0;
	for (int i = 0; i < R; i++){
		vector<int> vbuf;
		for (int j = 0; j < C; j++){
			if (S[idx] == '0'){ vbuf.push_back(0); }
			else{ vbuf.push_back(1); }
			idx++;
		}
		ret.push_back(vbuf);
	}
	return ret;
}
vector<vector<int> > split(vector<vector<int> >& arr)
{
	int y = 0;
	int x = 0;
	int Ymax = arr.size();
	int Xmax = arr[0].size();
	vector<vector<int> > ret;

	vector<int> vbuf;
	while (y < Ymax && x < Xmax)
	{
		for (int i = x; i < Xmax; ++i)
		{
			vbuf.push_back(arr[y][i]);
			if (vbuf.size() == 5){ ret.push_back(vbuf); vbuf.clear(); }
		}
		y++;

		for (int i = y; i < Ymax; ++i)
		{
			vbuf.push_back(arr[i][Xmax - 1]);
			if (vbuf.size() == 5){ ret.push_back(vbuf); vbuf.clear(); }
		}
		Xmax--;

		if (y < Ymax)
		{
			for (int i = Xmax - 1; i >= x; --i)
			{
				vbuf.push_back(arr[Ymax - 1][i]);
				if (vbuf.size() == 5){ ret.push_back(vbuf); vbuf.clear(); }
			}
			Ymax--;
		}

		if (x < Xmax)
		{
			for (int i = Ymax - 1; i >= y; --i)
			{
				vbuf.push_back(arr[i][x]);
				if (vbuf.size() == 5){ ret.push_back(vbuf); vbuf.clear(); }
			}
			x++;
		}
	}
	return ret;
}
char decode(vector<int> arr){
	char val = 'A' - 1;
	val += arr[0] * 16;
	val += arr[1] * 8;
	val += arr[2] * 4;
	val += arr[3] * 2;
	val += arr[4] * 1;
	if (val > 'Z' || val < 'A'){ val = ' '; }
	return val;
}
int main(){
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++){
		int R, C;
		string S;
		cin >> R >> C >> S;
		vector<vector<int> > arr = gen(R, C, S);
		vector<vector<int> > splited = split(arr);
		cout << tt << " ";
		for (int i = 0; i < splited.size(); i++){ cout << decode(splited[i]); }
		cout << endl;
	}
	system("pause");
}