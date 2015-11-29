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
#include<map>
#include<queue>
#include<list>
#include<deque>
#define INF 1987654321
using namespace std;
bool isexist(map<int, vector<pair<int, int> > > &point, int x, int y)
{
	if (point.find(x) == point.end()) return false;
	for (int i = 0; i < point[x].size(); i++){
		if (point[x][i].second == y){ return true; }
	}
	return false;
}

pair<int, int> solve(map<int, vector< pair<int, int> > >& point, vector<pair<int, int> >& pointid){
	int mmin = INF;
	int mmax = -1;
	int N = pointid.size();
	for (int i = 0; i<N; i++) {
		pair<int, int> pairbuf = pointid[i];
		vector<pair<int, int> > vpbuf = point[pairbuf.first];
		for (int j = 0; j<vpbuf.size(); j++) {
			if (vpbuf[j].second == pairbuf.second) continue;
			int dist = abs(vpbuf[j].second - pairbuf.second);
			if (isexist(point, pairbuf.first - dist, pairbuf.second)){
				if (isexist(point, vpbuf[j].first - dist, vpbuf[j].second)){
					mmin = min(dist, mmin);
					mmax = max(dist, mmax);
				}
			}
			if (isexist(point, pairbuf.first + dist, pairbuf.second)){
				if (isexist(point, vpbuf[j].first + dist, vpbuf[j].second)){
					mmin = min(dist, mmin);
					mmax = max(dist, mmax);
				}
			}
		}
	}
	return make_pair(mmin, mmax);
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		map<int, vector< pair<int, int> > > pointxy;
		vector<pair<int, int> > pointxyid(N, make_pair(0, 0));

		map<int, vector< pair<int, int> > > pointyx;
		vector<pair<int, int> > pointyxid(N, make_pair(0, 0));


		for (int i = 0; i<N; i++) {
			int x, y;
			cin >> x >> y;
			pair<int, int> pairbufxy = make_pair(x, y);
			pair<int, int> pairbufyx = make_pair(y, x);
			pointxyid[i] = pairbufxy;
			pointyxid[i] = pairbufyx;
			map<int, vector<pair<int, int> > >::iterator it1 = pointxy.find(pairbufxy.first);
			map<int, vector<pair<int, int> > >::iterator it2 = pointyx.find(pairbufyx.first);
			if (it1 != pointxy.end()) {
				it1->second.push_back(pairbufxy);
			}
			else {
				vector<pair<int, int> > v;
				v.push_back(pairbufxy);
				pointxy[pairbufxy.first] = v;
			}
			if (it2 != pointyx.end()) {
				it2->second.push_back(pairbufyx);
			}
			else {
				vector<pair<int, int> > v;
				v.push_back(pairbufyx);
				pointyx[pairbufyx.first] = v;
			}
		}
		pair<int, int> ret;
		if (pointxy.size() > pointyx.size()){ ret = solve(pointxy, pointxyid); }
		else{ ret = solve(pointyx, pointyxid); }
		cout << ret.first << " " << ret.second << endl;
	}

	system("pause");
}