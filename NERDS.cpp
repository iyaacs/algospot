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
const double INF = 1e200;
const double EPSILON = 1e-8;
const double PI = 2.0 * acos(0.0);
using namespace std;
class vector2 {
public:
	double x, y;
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	bool operator == (const vector2& rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator < (const vector2& rhs) const { if (x != rhs.x) return x < rhs.x; return y < rhs.y; }
	bool operator > (const vector2& rhs) const { if (x != rhs.x) return x > rhs.x; return y > rhs.y; }
	vector2 operator + (const vector2& rhs) const { return vector2(x + rhs.x, y + rhs.y); }
	vector2 operator - (const vector2& rhs) const { return vector2(x - rhs.x, y - rhs.y); }
	vector2 operator - () const { return vector2(-x, -y); }
	vector2 operator * (double rhs) const { return vector2(x * rhs, y * rhs); }
	double norm() const { return hypot(x, y); }
	vector2 normalize() const { double n = norm(); return vector2(x / n, y / n); }
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
	double dot(const vector2& rhs) const { return x * rhs.x + y * rhs.y; }
	double cross(const vector2& rhs) const { return x * rhs.y - rhs.x * y; }
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}


bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	double det = (b - a).cross(d - c);
	if (det == 0) return false;
	p = a + (b - a) * ((c - a).cross(d - c) / det);
	return det;
}

bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	if (b == c) { p = b; return true; }
	if (a == d) { p = a; return true; }
	return false;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	return x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2;
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (!lineIntersection(a, b, c, d, p)) return parallelSegments(a, b, c, d, p);
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

double disjoint(double a, double b, double c, double d) {
	if (a > b) swap(a, b); if (c > d) swap(c, d);
	return b < c || d < a;
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0)
		return !disjoint(a.x, b.x, c.x, d.x) &&
		!disjoint(a.y, b.y, c.y, d.y);
	return ab <= 0 && cd <= 0;
}

vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	vector2 delta = (b - a).normalize();
	return a + delta * (p - a).dot(delta);
}

double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}

double area(const vector<vector2>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		ret = ret + (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return fabs(ret) / 2.0;
}

bool isInside(vector2 q, const vector<vector2>& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX)
				++crosses;
		}
	}
	return crosses % 2 > 0;
}
typedef vector<vector2> polygon;
polygon	wrap(vector<vector2>& points){
	int n = points.size();
	polygon ret;
	vector2 pivot;
	pivot.y = INF;
	pivot.x = INF;
	for (int i = 0; i < n; i++){
		if (pivot>points[i]){ pivot = points[i]; }
	}
	ret.push_back(pivot);
	while (true){
		vector2 now = ret.back();
		vector2 next = points[0];
		for (int i = 1; i < n; i++){
			double cross = ccw(now, next, points[i]);
			double one = (next - now).norm();
			double two = (points[i] - now).norm();
			double dist = one - two;
			if (cross > 0 || (cross == 0 && dist < 0)){ next = points[i]; }
		}
		if (next == pivot){ break; }
		ret.push_back(next);
	}
	return ret;
}
bool isoverlap(polygon& a, polygon& b){
	int n = a.size();
	int m = b.size();
	for (int i = 0; i < n; i++){
		if (isInside(a[i], b)){ return true; }
	}
	for (int i = 0; i < m; i++){
		if (isInside(b[i], a)){ return true; }
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (segmentIntersects(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m])){ return true; }
		}
	}
	return false;
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		vector<vector2> nerd;
		vector<vector2> notnerd;
		for (int i = 0; i < N; i++){
			int a, b, c;
			cin >> a >> b >> c;
			vector2 v2buf;
			v2buf.y = b;
			v2buf.x = c;
			if (a){ nerd.push_back(v2buf); }
			else{ notnerd.push_back(v2buf); }
		}
		polygon nerd2 = wrap(nerd);
		polygon notnerd2 = wrap(notnerd);
		if (isoverlap(nerd2, notnerd2)){ cout << "THEORY IS INVALID" << endl; }
		else{ cout << "THEORY HOLDS" << endl; }
	}
	system("pause");
}