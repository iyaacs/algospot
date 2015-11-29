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
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int C;
	cin >> C;
	while (C--){
		int N;
		cin >> N;
		vector<vector<int> > graph;
		for (int i = 0; i < N; i++){
			vector<int> vbuf;
			for (int j = 0; j < N; j++){
				int buf;
				cin >> buf;
				vbuf.push_back(buf);
			}
			graph.push_back(vbuf);
		}

		int M;
		cin >> M;
		vector<int> ans;
		for (int i = 0; i < M; i++){
			vector<int> chk;
			for (int j = 0; j < N; j++){ chk.push_back(0); }
			int a, b;
			cin >> a >> b;
			a--; b--;
			vector<int> virus;
			virus.push_back(a);
			virus.push_back(b);

			int virusori = 2;
			for (int j = 0; j < N; j++){
				for (int k = 0; k < virus.size(); k++){
					if (graph[j][virus[k]] == 1){ chk[j]++; }
				}
			}
			////////////////
			route:
			for (int j = 0; j < N; j++){
				if (chk[j] >= 2){
					int flag = 0;
					for (int k = 0; k < virus.size(); k++){
						if (virus[k] == j){ flag = 1; break; }
					}
					if (flag == 0){
						virus.push_back(j);
					}
				}
			}

			for (int j = 0; j < N; j++){
				for (int k = virusori; k < virus.size(); k++){
					if (graph[j][virus[k]] == 1){ chk[j]++; }
				}
			}

			if (virusori != virus.size()){ virusori = virus.size(); goto route; }
			////////////////

			ans.push_back(virus.size());
			}
		for (int i = 0; i < ans.size(); i++){
			if (i != ans.size() - 1){ cout <<	 ans[i] << " "; }
			else{ cout << ans[i]; }
		}
		cout << endl;

		}
		

	system("pause");
	}