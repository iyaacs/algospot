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
using namespace std;
int main(){
ios::sync_with_stdio(false);
int T;
cin >> T;
while (T--){
	int n, depend;
	cin >> n >> depend;
	vector<vector<int> >graph;
	for (int i = 0; i < 128; i++){
		vector<int> vbuf;
		for (int j = 0; j < 128; j++){ vbuf.push_back(0); }
		graph.push_back(vbuf);
	}
	for (int i = 0; i < depend; i++){
		string buf;
		cin >> buf;
		graph[buf[0]][buf[1]] = 1;
	}
	string selected = "";
		for (int k = 0; k < n; k++){
			for (int i = 'A'; i < 'A' + n; i++){
				int flag = 1;
				char selectchar = 0;
				for (int j = 'A'; j < 'A' + n; j++){
					if (graph[j][i] == 1){ flag = 0; break; }
				}
				if (flag == 0){ continue; }

				selectchar = i;
				for (int j = 'A'; j < 'A' + n; j++){
					graph[selectchar][j] = 0;
				}
				if (selected.find(selectchar) > n * 2){ selected.push_back(selectchar); break; }
			}
		}
	cout << selected << endl;
}

system("pause");
}