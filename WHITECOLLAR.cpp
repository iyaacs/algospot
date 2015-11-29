#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <set>

using namespace std;

struct city{
	vector<int> move;
	int m_min;
};
city c_list[1005];
int order[1005];
bool suc[1005];

int N, M;
vector<int> mhash;

void loop(int i, int k){
	for (vector<int>::iterator ite = c_list[i].move.begin(); ite != c_list[i].move.end(); ++ite){

		order[k] = *ite;
		if (*ite != N && c_list[*ite].m_min > k){
			c_list[*ite].m_min = k;
			loop(*ite, k + 1);
		}
		else if (suc[*ite] && c_list[*ite].m_min == k){
			for (int a = 1; a < k; a++){
				if (!suc[order[a]]){
					mhash.push_back(order[a]);
					suc[order[a]] = true;
				}
			}
		}
		if (*ite == N){
			if (c_list[*ite].m_min > k){
				c_list[*ite].m_min = k;
				memset(suc, 0, sizeof(bool) * 1005);
				mhash.clear();
				for (int a = 0; a <= k; a++){
					mhash.push_back(order[a]);
					suc[order[a]] = true;
				}
			}
			else if (c_list[*ite].m_min == k){
				for (int a = 1; a <= k; a++){
					if (!suc[order[a]]){
						mhash.push_back(order[a]);
						suc[order[a]] = true;
					}
				}
			}
		}
	}
}
int main(){
	int caseNum;
	cin >> caseNum;
	while (caseNum--){
		cin >> N >> M;
		for (int i = 1; i <= N; i++){
			c_list[i].move.clear();
			c_list[i].m_min = INT_MAX;
		}
		for (int i = 0; i < M; i++){
			int start, end;
			cin >> start >> end;
			c_list[start].move.push_back(end);
		}

		c_list[1].m_min = 0;
		order[0] = 1;
		loop(1, 1);

		sort(mhash.begin(), mhash.end());
		for (vector<int>::iterator ite = mhash.begin(); ite != mhash.end(); ++ite){
			cout << *ite << " ";
		}

		cout << endl;
	}
}