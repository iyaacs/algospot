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
void solve(int N, int M,vector<vector<int> >& graph, vector<vector<int> >& path,int x, int y, int count, int& allcount){
    if (graph[x][y] != -1){
        if (count != graph[x][y]){
            return;
        }
    }
    if (x == N - 1 && y == M - 1 && count == N*M - 1){
        allcount += 1;
        return;
    }
    path[x][y] = 1;

    if (x != 0 && path[x - 1][y] == 0){
        solve(N,M,graph,path,x - 1, y, count + 1,allcount);
    }
    if (y != 0 && path[x][y - 1] == 0){
        solve(N,M,graph,path,x, y - 1, count + 1,allcount);
    }
    if (x != N - 1 && path[x + 1][y] == 0){
        solve(N,M,graph,path,x + 1, y, count + 1,allcount);
    }
    if (y != M - 1 && path[x][y + 1] == 0){
        solve(N,M,graph,path,x, y + 1, count + 1,allcount);
    }
    path[x][y] = 0;
}
 
int main(){
	std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--){
    	int allcount=0;
    	int N,M;
        vector<vector<int> > graph;
        vector<vector<int> > path;
        cin>>N>>M;
        for(int i=0;i<N;i++){
        	vector<int> vbuf;
        	for(int j=0;j<M;j++){vbuf.push_back(0);}
        	graph.push_back(vbuf);
        	path.push_back(vbuf);
        }
 
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
            	int buf;
            	cin>>buf;
            	graph[i][j]=buf;
            }
        }
        solve(N,M,graph,path,0, 0, 0,allcount);
        cout<<allcount<<endl;

    }
}