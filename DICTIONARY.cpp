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
vector <vector <int> > adj;
vector <string> word;
vector <int> visitted(26, 0);
vector <int>order;
void init()
{
	adj = vector < vector<int> >(26, vector<int>(26, 0));
	for (int j = 1; j < word.size(); j++)
	{
		int i = j - 1, length = min(word[i].size(), word[j].size());
		for (int k = 0; k < length; k++)
		{
			if (word[i][k] != word[j][k])
			{
				int from = word[i][k] - 'a';
				int to = word[j][k] - 'a';
				adj[from][to] = 1;
				break;
			}
		}
	}
}
void dfs(int here)
{
	visitted[here] = 1;
	for (int there = 0; there < adj.size(); there++)
		if (adj[here][there] && !visitted[there])
			dfs(there);
	order.push_back(here);
}
vector<int> topologicalsort()
{
	int n = adj.size();
	visitted = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; i++)
		if (!visitted[i])dfs(i);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();
	for (int i = 0; i < order.size(); i++)
		return order;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int w_size; 
		cin>>w_size;
		word = vector<string>(w_size);
		for (int i = 0; i < w_size; i++)
			{cin >> word[i];}
		
		init();
		order = topologicalsort();
		if (order.empty()){
			cout<<"INVALID HYPOTHESIS"<<endl;
		}
		else{
			for (int i = 0; i < order.size(); i++)
			{
			    char buf=order[i]+'a';
			    cout<<buf;
			}
		cout<<endl;
		    
		}
	}
	system("pause");
}