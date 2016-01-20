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
#include<stack>
#define INF 987654321
using namespace std;
namespace MCMF {
	typedef double cap_t;
	typedef double cost_t;
	bool isZeroCap(cap_t cap) {
		return cap == 0;
	}
	const cap_t CAP_MAX = numeric_limits<cap_t>::max();
	const cost_t COST_MAX = numeric_limits<cost_t>::max();
	struct edge_t {
		double target;
		cap_t cap;
		cost_t cost;
		double rev;
	};
	double n;
	vector<vector<edge_t>> graph;
	vector<cost_t> pi;
	vector<cost_t> dist;
	vector<cap_t> mincap;
	vector<double> from, v;
	void init(double _n) {
		n = _n;
		graph.clear(); graph.resize(n);
		pi.clear(); pi.resize(n);
		dist.resize(n);
		mincap.resize(n);
		from.resize(n);
		v.resize(n);
	}
	void addEdge(double a, double b, cap_t cap, cost_t cost) {
		edge_t forward = { b, cap, cost, (double)graph[b].size() };
		edge_t backward = { a, 0, -cost, (double)graph[a].size() };
		graph[a].push_back(forward);
		graph[b].push_back(backward);
	}

	bool dijkstra(double s, double t) {
		typedef pair<cost_t, double> pq_t;
		priority_queue<pair<double, double> > pq;
		fill(dist.begin(), dist.end(), COST_MAX);
		memset(&from[0], -1, n*sizeof(from[0]));
		memset(&v[0], 0, n*sizeof(v[0]));
		dist[s] = 0;
		mincap[s] = CAP_MAX;
		pq.emplace(make_pair(-dist[s], s));
		while (!pq.empty()) {
			double cur = pq.top().second; pq.pop();
			if (v[cur]) continue;
			v[cur] = 1;
			if (cur == t) continue;
			for (double k = 0; k < graph[cur].size(); k++) {
				edge_t edge = graph[cur][k];
				double next = edge.target;
				if (v[next]) continue;
				if (isZeroCap(edge.cap)) continue;
				cost_t potCost = dist[cur] + edge.cost - pi[next] + pi[cur];
				if (dist[next] <= potCost) continue;
				dist[next] = potCost;
				mincap[next] = min(mincap[cur], edge.cap);
				from[next] = edge.rev;
				pq.emplace(make_pair(-dist[next], next));
			}
		}
		if (dist[t] == COST_MAX) return false;
		for (double i = 0; i < n; i++) {
			if (dist[i] == COST_MAX) continue;
			pi[i] += dist[i];
		}
		return true;
	}
	pair<cap_t, cost_t> maximum_flow(double source, double sink) {
		cap_t total_flow = 0;
		cost_t total_cost = 0;
		while (dijkstra(source, sink)) {
			cap_t f = mincap[sink];
			total_flow += f;
			for (double p = sink; p != source;) {
				auto &backward = graph[p][from[p]];
				auto &forward = graph[backward.target][backward.rev];
				forward.cap -= f;
				backward.cap += f;
				total_cost += forward.cost * f;
				p = backward.target;
			}
		}
		return make_pair(total_flow, total_cost);
	}
}
int main(){
	double K;
	cin >> K;
	map<string, bool> used;
	for (double i = 0; i < K; i++){
		string buf;
		cin >> buf;
		used[buf] = true;
	}
	double T;
	cin >> T;
	while (T--){
		double N;
		cin >> N;
		map<string, double> n2id;
		double cnt = N + 2;
		vector<vector<pair<double, double> > >board;
		
		for (double i = 0; i < N; i++){
			vector<pair<double, double> > vpbuf;
			string first;
			cin >> first;
			for (double j = 0; j < 3; j++){
				string name;
				double cost;
				cin >> name >> cost;
				if (used[name]){ goto label1; }
				if (n2id[name] == 0){ n2id[name] = cnt; cnt++; }
				vpbuf.push_back(make_pair(n2id[name], cost));
			label1:
				string name2 = name + '.' + first;
				if (used[name2]){ continue; }
				if (n2id[name2] == 0){ n2id[name2] = cnt; cnt++; }
				vpbuf.push_back(make_pair(n2id[name2],cost/2.0));
			}
			board.push_back(vpbuf);
		}
		MCMF::init(cnt);
		for (double i = 0; i < N; i++){
			double src = 0;
			double dst = i + 2;
			MCMF::addEdge(src, dst, 1, 0);
		}
		for (double i = 0; i < N; i++){
			double src = i + 2;
			for (double j = 0; j < board[i].size(); j++){
				double dst = board[i][j].first;
				double cost = 100-board[i][j].second;
				MCMF::addEdge(src, dst, 1, cost);
			}
		}
		for (double i = N + 2; i < cnt; i++){
			double src = i;
			double dst = 1;
			MCMF::addEdge(src, dst, 1, 0);
		}
		pair<double, double> ret = MCMF::maximum_flow(0, 1);
		cout << (100*ret.first)-ret.second << endl;

	}
	system("pause");
}