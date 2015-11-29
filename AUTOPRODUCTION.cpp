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
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		vector<int> R;
		vector<vector<int> >C;
		cin >> N;
		for (int i = 0; i < N; i++){
			int r, c;
			cin >> r >> c;
			R.push_back(r);
			vector<int> vbuf;
			for (int j = 0; j < c; j++){
				int buf;
				cin >> buf;
				buf *= (-1);
				vbuf.push_back(buf);
			}
			C.push_back(vbuf);
		}

		for (int i = 0; i < N; i++){
			sort(C[i].begin(), C[i].end());
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < C[i].size(); j++){
				C[i][j] *= (-1);
			}
		}
		
		int sum = N;
		int ret = 0;
		vector<int> factor;
		vector<int> num;
		for (int i = 0; i < N; i++){
			num.push_back(0);
			factor.push_back(C[i][0]);
		}
		while (true){
			for (int i = 0; i < N; i++){
				factor[i] -= R[i];
			route:
				if (factor[i] < 0){
					if (sum >= 10){ goto end; }
					else{
						sum++;
						num[i]++;
						if (num[i] >= C[i].size()){ goto end; }
						factor[i] += C[i][num[i]];
						if (factor[i] < 0){ goto route; }
					}
				}
				
			}
			ret++;
		}
		end:
		cout << ret << endl;
	}
	system("pause");
}