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
#define INF 9876543212
using namespace std;

int solve(vector<string>& graph, int x, int y, string str, string goal, map<string,map<int,map<int,int> > >& cache){
	// 0 : default, 1 : false, 2: true
	if (x < 0){ return 1; }
	if (x >= 5){ return 1; }
	if (y < 0){ return 1; }
	if (y >= 5){ return 1; }
	if(str.length() == goal.length()){return 1;}
	
	str += graph[x][y];
//	cout<<x<<" "<<y<<" "<<str<<endl;
	if (goal.substr(0, str.length()) != str){return 1;}
	
	int& ret = cache[str][x][y];
	if (ret != 0){return ret;}
	
	if (str == goal){return ret=2;}
	ret = max(ret,1);
	
	
	
	
	ret = max(ret , solve(graph, x - 1, y - 1, str, goal,cache));
	ret = max(ret , solve(graph, x, y - 1, str, goal,cache));
	ret = max(ret , solve(graph, x + 1, y - 1, str, goal,cache));
	ret = max(ret , solve(graph, x + 1, y, str, goal,cache));
	ret = max(ret , solve(graph, x + 1, y + 1, str, goal,cache));
	ret = max(ret , solve(graph, x, y + 1, str, goal,cache));
	ret = max(ret , solve(graph, x - 1, y + 1, str, goal,cache));
	ret = max(ret , solve(graph, x - 1, y, str, goal,cache));
	return ret;
}

int main(){
	int C;
	cin >> C;
	while (C--){
		vector<string> graph;
		

		for (int i = 0; i < 5; i++){
			string str;
			cin >> str;
			graph.push_back(str);
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			map<string,map<int,map<int,int> > > cache;
			string goal;
			cin >> goal;
			int ret = 1;
			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 5; j++){
					if (goal[0] == graph[i][j]){ ret = max(ret, solve(graph, i, j, "", goal, cache)); }
				}
			}
			cout << goal << " ";
			if (ret == 2){ cout << "YES" << endl; }
			else{ cout << "NO" << endl; }


		}
	}
	system("pause");
}