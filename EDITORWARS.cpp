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
#define INF 987654321
using namespace std;
class UnionFind{
public:
	vector<int> parent;
	vector<int> rank;
	vector<int> enemy;
	vector<int> size;
	UnionFind(int n) :parent(n), rank(n, 0), enemy(n, -1), size(n, 1){
		for (int i = 0; i < n; i++){
			parent[i] = i;
		}
	}
	int find(int u){
		if (parent[u] == u){ return u; }
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v){
		if (u == -1 || v == -1){ return max(u, v); }
		u = find(u);
		v = find(v);
		if (u == v){ return u; }
		if (rank[u]>rank[v]){ swap(u, v); }
		if (rank[u] == rank[v]){ rank[v]++; }
		parent[u] = v;
		size[v] += size[u];
		return v;
	}
	bool dis(int u, int v){
		u = find(u);
		v = find(v);
		if (u == v){ return false; }
		int a = merge(u, enemy[v]);
		int b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}
	bool ack(int u, int v){
		u = find(u);
		v = find(v);
		if (enemy[u] == v){ return false; }
		int a = merge(u, v);
		int b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1){ enemy[b] = a; }
		return true;
	}
};
int solve(UnionFind& u, int N){
	int ret = 0;
	for (int i = 0; i < N; i++){
		if (u.find(i) == i){
			int enemy = u.enemy[i];
			if (enemy > i){ continue; }
			int size = u.size[i];
			int enemysize;
			if (enemy == -1){ enemysize = 0; }
			else{ enemysize = u.size[enemy]; }
			ret += max(size, enemysize);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		UnionFind uf(N);
		int retflag = 0;
		for (int i = 0; i < M; i++){
			string a;
			int b, c;
			cin >> a >> b >> c;
			if (retflag == 0){
				if (a == "ACK"){
					bool flag = uf.ack(b, c);
					if (flag == false){ cout << "CONTRADICTION AT "<<i + 1 << endl; retflag = 1; }
				}
				else{
					bool flag = uf.dis(b, c);
					if (flag == false){ cout << "CONTRADICTION AT " << i + 1 << endl; retflag = 1; }
				}
			}
		}
		if (retflag == 0){ cout << "MAX PARTY SIZE IS " << solve(uf, N) << endl; }
	}
	system("pause");
}