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
#define MOD 20090711
using namespace std;
void init(vector<string>& arr, vector<vector<int> >& adj, vector<int>& in, vector<int>& out, vector<vector<vector<string> > >& words){
	int N = arr.size();
	for (int i = 'a'; i <= 'z'; i++){
		in.push_back(0);
		out.push_back(0);
		vector<int> vbuf;
		vector<vector<string> > vvsbuf;
		for (int j = 'a'; j <= 'z'; j++){
			vbuf.push_back(0);
			vector<string> vsbuf;
			vvsbuf.push_back(vsbuf);
		}
		adj.push_back(vbuf);
		words.push_back(vvsbuf);
	}
	for (int i = 0; i < N; i++){
		char start = arr[i][0];
		char end = arr[i][arr[i].length() - 1];
		start -= 'a';
		end -= 'a';
		adj[start][end]++;
		words[start][end].push_back(arr[i]);
		out[start]++;
		in[end]++;
	}
}
void geneuler(int src, vector<int>& euler, vector<vector<int> >& adj){
	for (int dst = 0; dst < adj.size(); dst++){
		while (adj[src][dst]>0){
			adj[src][dst]--;
			geneuler(dst, euler, adj);
		}
	}
	euler.push_back(src);
}

vector<int> geteuler(vector<int>& in, vector<int>& out, vector<vector<int> >& adj){
	vector<int> euler;
	for (int i = 0; i < 26; i++){
		if (out[i] == in[i] + 1){
			geneuler(i, euler, adj);
			return euler;
		}
	}
	for (int i = 0; i < 26; i++){
		if (out[i]){
			geneuler(i, euler, adj);
			return euler;
		}
	}
	return euler;
}
bool iseuler(vector<int>& in, vector<int>& out){
	int start = 0;
	int end = 0;
	for (int i = 0; i < 26; i++){
		int val = out[i] - in[i];
		if (val < -1 || 1 < val){ return false; }
		if (val == 1){ start++; }
		if (val == -1){ end++; }
	}
	bool ret = false;
	if (start == end && start == 1){ ret = true; }
	if (start == end && start == 0){ ret = true; }
	return ret;
}

int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<string> arr;
		vector<vector<int> > adj;
		vector<vector<vector<string> > > words;
		vector<int> in;
		vector<int> out;
		for (int i = 0; i < N; i++){
			string buf;
			cin >> buf;
			arr.push_back(buf);
		}
		init(arr, adj, in, out, words);
		if (iseuler(in, out)){
			bool iscircuit;
			string retstr = "";
			vector<int> tempeuler = geteuler(in, out, adj);
			vector<int> euler;
			for (int i = 0; i < tempeuler.size(); i++){
				euler.push_back(tempeuler[tempeuler.size() - 1 - i]);
			}
			vector<int> euler2;
			vector<int> euler3;
			if (euler[0] == euler[euler.size() - 1]){
				string retstr2 = "";
				string retstr3 = "";
				vector<vector<vector<string> > > words2 = words;
				vector<vector<vector<string> > > words3 = words;
				euler2 = euler;
				euler2.pop_back();
				for (int i = 1; i < euler.size(); i++){
					euler3.push_back(euler[i]);
				}

				for (int i = 0; i < N - 1; i++){
					int src2 = euler2[i];
					int src3 = euler3[i];
					int dst2 = euler2[i + 1];
					int dst3 = euler3[i + 1];
					//cout << src2 << " " << src3 << " " << dst2 << " " << dst3 << endl;
					retstr2 += words2[src2][dst2].back();
					retstr2 += " ";
					retstr3 += words3[src3][dst3].back();
					retstr3 += " ";

					words2[src2][dst2].pop_back();
					words3[src3][dst3].pop_back();
				}
				for (int i = 0; i < 26; i++){
					if (words2[N - 1][i].size() != 0){ retstr2 += words2[N - 1][i].back(); }
					if (words3[N - 1][i].size() != 0){ retstr3 += words3[N - 1][i].back(); }
				}
				string finalretstr = "";
				int finalflag = 0;
				if (retstr2.length()>retstr3.length()){ finalflag = 1; }
				if (finalflag == 0){ finalretstr = retstr3; }
				else{ finalretstr = retstr2; }
				cout << finalretstr << endl;
			}
			else{
				for (int i = 0; i < euler.size() - 1; i++){
					int src = euler[i];
					int dst = euler[i + 1];
					cout << words[src][dst].back() << " ";
					words[src][dst].pop_back();
				}
				cout << endl;
			}


		}
		else{ cout << "IMPOSSIBLE" << endl; }
	}


	system("pause");
}