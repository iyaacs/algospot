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

int main(){
	int T;
	cin >> T;
	while (T--){
		int jump;
		vector<vector<int> > arr;
		int n;
		cin >> jump;
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;
		cin >> n;
		jump *= jump;

		vector<int> vbuf;
		vbuf.push_back(startx);
		vbuf.push_back(starty);
		arr.push_back(vbuf);
		vbuf.clear();
		vbuf.push_back(endx);
		vbuf.push_back(endy);
		arr.push_back(vbuf);
		vbuf.clear();
		for (int i = 2; i < n+2; i++){
			int x, y;
			cin >> x >> y;
			vector<int> vbuf;
			vbuf.push_back(x);
			vbuf.push_back(y);
			arr.push_back(vbuf);
		}
		
		int i, m;
		for (i = 1, m = 2; i<m; i++){
			if (pow(arr[i][0] - startx, 2) + pow(arr[i][1] - starty, 2) <= jump) break;
			for (int k = m; k<n+2; k++){
				if (pow(arr[i][0] - arr[k][0], 2) + pow(arr[i][1] - arr[k][1], 2) <= jump){
					swap(arr[m][0], arr[k][0]);
					swap(arr[m][1], arr[k][1]);
					m++;
				}
			}
		}
		if (i < m){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
		
	}
	system("pause");
}