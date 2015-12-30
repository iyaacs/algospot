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
#define SIZE 4000

int tree[SIZE+10][SIZE+10];

int read(int y, int x)
{
	int sum;
	int x1;

	sum = 0;
	while (y > 0){
		x1 = x;
		while (x1 > 0){
			sum += tree[y][x1];
			x1 -= (x1 & -x1);
		}
		y -= (y & -y);
	}

	return sum;
}

void update(int y, int x, int val)
{
	int x1;

	while (y <= SIZE){
		x1 = x;
		while (x1 <= SIZE){
			tree[y][x1] += val;
			x1 += (x1 & -x1);
		}
		y += (y & -y);
	}
}
int gridsum(int y1, int x1, int y2, int x2){
	int ret = read(y2, x2);
	ret -= read(y1-1, x2);
	ret -= read(y2, x1-1);
	ret += read(y1-1, x1-1);
	return ret;
}

struct rect{
	int x, y, w, h;
};
rect getintersection(rect& r1, rect& r2){
	rect ret;
	ret.x = -INF;
	ret.y = -INF;
	ret.w = -INF;
	ret.h = -INF;
	if (r1.x > r2.x + r2.w) return ret;
	if (r1.x + r1.w < r2.x) return ret;
	if (r1.y > r2.y + r2.h) return ret;
	if (r1.y + r1.h < r2.y) return ret;

	ret.x = max(r1.x, r2.x);
	ret.y = max(r1.y, r2.y);
	ret.w = min(r1.x + r1.w, r2.x + r2.w) - ret.x;
	ret.h = min(r1.y + r1.h, r2.y + r2.h) - ret.y;

	return ret;
}
int dist(int y1, int x1, int y2, int x2){
	return max(abs(y1 - y2), abs(x2 - x1));
}

int dist(pair<int, int> A, pair<int, int> B){
	return max(abs(A.first - B.first), abs(A.second - B.second));
}

int main()
{
	int T;
	cin >> T;
	while (T--){
		for (int i = 0; i < SIZE+10; i++){
			for (int j = 0; j < SIZE+10; j++){
				tree[i][j] = 0;
			}
		}
		int M, N;
		cin >> M >> N;
		vector<pair<int, int> > cvs;
		for (int i = 0; i < M; i++){
			int y, x;
			cin >> y >> x;
			y += (SIZE / 2);
			x += (SIZE / 2);
			cvs.push_back(make_pair(y, x));
		}
		vector<pair<int, int> > room;
		for (int i = 0; i < N; i++){
			int y, x;
			cin >> y >> x;
			y += (SIZE / 2);
			x += (SIZE / 2);
			room.push_back(make_pair(y, x));
		}

		for (int i = 0; i < N; i++){
			rect ro;
			int td = dist(room[i], cvs[0]);
			int ty = cvs[0].first;
			int tx = cvs[0].second;
			ty -= td;
			tx -= td;
			ro.y = ty;
			ro.x = tx;
			ro.h = (2 * td);
			ro.w = (2 * td);
			bool flag = true;
			for (int j = 0; j < M; j++){
				int d = dist(room[i], cvs[j]);
				d--;
				int y = cvs[j].first;
				int x = cvs[j].second;
				y -= d;
				x -= d;
				rect r;
				r.y = y;
				r.x = x;
				r.h = (2 * d);
				r.w = (2 * d);
				ro = getintersection(ro, r);
				if (ro.h == -INF){ flag = false; break; }
			}
			int pv = gridsum(ro.y, ro.x, ro.y + ro.h, ro.x + ro.w);
			update(room[i].first, room[i].second, 1);
			if (i == 0){ cout << "G "; }
			else{
				if (!flag){ cout << "G "; continue; }
				if (pv !=0){ cout << "B "; }
				else{ cout << "G "; }
			}
		}
		cout << endl;

	}
	system("pause");
}