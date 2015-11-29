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
int gcd(int a, int b) {
    while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return abs(a);
}
pair<int, int> reduceFraction(int bunja, int bunmo) {
	static int frac[2];
	frac[0] = bunja;
	frac[1] = bunmo;
	if (frac[1] == 0) {
		frac[0] = NULL;
		frac[1] = NULL;
		return make_pair(0, 0);
	}
	int gcd_result = gcd(frac[0], frac[1]);
	frac[0] = frac[0] / gcd_result;
    frac[1] = frac[1] / gcd_result;

	return make_pair(frac[0],frac[1]);
}

void dfs(vector<vector<double> >& adj, int here, vector<bool>& visited, vector<int>& route){
	if (here >= adj.size()){ return; }
	visited[here] = true;
	route.push_back(here);
	for (int i = 0; i < adj[here].size(); i++){
		if (adj[here][i] != 0){
			if (!visited[i]){
				dfs(adj, i, visited,route);
			}
		}
	}
}

void dfs2(vector<vector<pair<int, int> > >& adj2, int here, vector<bool>& visited, vector<int>& route){
	if (here >= adj2.size()){ return; }
	visited[here] = true;
	route.push_back(here);
	for (int i = 0; i < adj2[here].size(); i++){
		if (adj2[here][i] != make_pair(0,0)){
			if (!visited[i]){
				dfs2(adj2, i, visited, route);
			}
		}
	}
}

void dfs3(int here, vector<vector<int> >& adj, vector<bool>& visited, int& kk){
	//cout << here << endl;
	kk++;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++){
		int next = adj[here][i];
		if (!visited[next]){ dfs3(next,adj,visited,kk); }
	}
}

int dfsall(vector<vector<int> >& adj){
	vector<bool> visited = vector<bool>(adj.size(), false);
	int mmax = 0;
	for (int i = 0; i < adj.size(); i++){
		int kk = 0;
		if (!visited[i]){ dfs3(i,adj,visited,kk); }
		mmax = max(mmax, kk);
	}
		return mmax;
}

int main(){
    int T;
    cin >> T;
	while (T--){
	    int N, M;
	    cin >> N >> M;
	    vector<vector<int> > adj;
	    for (int i = 0; i < N; i++){
		    vector<int> vbuf;
		    adj.push_back(vbuf);
        }
	    for (int i = 0; i < M; i++){
		    int a, b;
		    cin >> a >> b;
		    adj[a].push_back(b);
	    	adj[b].push_back(a);
	    }
	cout<<dfsall(adj)<<endl;
    }
    system("pause");
}			