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
#define INF 1987654321
using namespace std;
vector<pair<int, int> >dir;
bool solve(vector<string>& graph2, pair<int,int>& from, pair<int,int>& to, int seg, int rows, int cols, int& ans, char c)
{
	if (seg >= 3) return false;

	if (to.first < 0 || to.first >= rows || to.second < 0 || to.second >= cols)
	{
		return false;
	}

	if (graph2[to.first][to.second] == c) {
		ans++;
		graph2[to.first][to.second] = '*';
		return true;
	}

	if (graph2[to.first][to.second] != '.')
		return false;

	graph2[to.first][to.second] = '*';

	for (int i = 0; i < 4; i++)
	{
		int ni = to.first + dir[i].first;
		int nj = to.second + dir[i].second;

		pair<int, int> next = make_pair(ni, nj);
		int nextseg = seg;
		if (from.first != next.first && from.second != next.second) {
			nextseg++;
		}
		solve(graph2, to, next, nextseg, rows, cols, ans, c);
	}
	graph2[to.first][to.second] = '.';

	return false;
}

int main()
{
	dir.push_back(make_pair(-1, 0));
	dir.push_back(make_pair(1, 0));
	dir.push_back(make_pair(0, -1));
	dir.push_back(make_pair(0, 1));

	int T;
	cin >> T;
	while (T--)
	{
		vector<string> graph;
		vector<string> graph2;
		int rows, cols;
		cin >> rows >> cols;
		for (int i = 0; i < rows; i++){
			string buf;
			cin >> buf;
			graph.push_back(buf);
		}

		int ans = 0;
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (isalpha(graph[i][j]))
				{
					pair<int, int> key = make_pair(i, j);
					char c = graph[i][j];
					graph2 = graph;
					graph2[i][j] = '.';
					solve(graph2, key, key, 0, rows, cols, ans, c);
					graph[i][j] = '*';
				}
			}
		}
		cout << ans << endl;
	}
	system("pause");
}