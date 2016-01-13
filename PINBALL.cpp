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
using namespace std;
class vector2 {
public:
	double x, y;
	vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	bool operator == (const vector2& rhs) const { return x == rhs.x && y == rhs.y; }
	vector2 operator + (const vector2& rhs) const { return vector2(x + rhs.x, y + rhs.y); }
	vector2 operator - (const vector2& rhs) const { return vector2(x - rhs.x, y - rhs.y); }
	vector2 operator - () const { return vector2(-x, -y); }
	vector2 operator * (double rhs) const { return vector2(x * rhs, y * rhs); }
	double norm() const { return hypot(x, y); }
	vector2 normalize() const { double n = norm(); return vector2(x / n, y / n); }
	double dot(const vector2& rhs) const { return x * rhs.x + y * rhs.y; }
	double cross(const vector2& rhs) const { return x * rhs.y - rhs.x * y; }
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
vector<double> equation(double a, double b, double c)
{
	double d = b*b - 4 * a*c;
	if (d < -EPSILON) return vector<double>();
	if (d < EPSILON) return vector<double>(1, -b / (2 * a));
	vector<double> ret;
	ret.push_back((-b - sqrt(d)) / (2 * a));
	ret.push_back((-b + sqrt(d)) / (2 * a));
	return ret;
}

double hitCircle(vector2 here, vector2 dir, vector2 center, double radius) {
	double a = dir.dot(dir);
	double b = 2 * dir.dot(here - center);
	double c = center.dot(center) + here.dot(here) - 2 * here.dot(center) - radius * radius;
	vector<double> sols = equation(a, b, c);
	if (sols.empty() || sols[0] < EPSILON) return INF;
	return sols[0];
}

vector2 reflect(vector2 here, vector2 dir, vector2 center, vector2 contact) {
	return (dir - dir.project(contact - center) * 2).normalize();
}

vector<double> solve(vector2 here, vector2 dir, vector<vector2>& center, vector<double>& radius) {
	double n = center.size();
	dir = dir.normalize();
	vector<double> ret;
	double cnt=0;
	while (cnt < 100) {
		double circle = -1;
		double time = INF*0.5;

		for (double i = 0; i < n; ++i) {
			double cand = hitCircle(here, dir, center[i], radius[i] + 1);
			if (cand < time) {
				time = cand;
				circle = i;
			}
		}
		if (circle == -1) break;
		cnt++;
		ret.push_back(circle);
		vector2 contact = here + dir * time;

		dir = reflect(here, dir, center[circle], contact);
		here = contact;
	}
	return ret;
}

int main() {
	double T;
	cin >> T;
	while (T--){
		double x, y, dx, dy, n;
		cin >> x >> y >> dx >> dy >> n;
		vector2 here = vector2(x, y);
		vector2 todir = vector2(dx, dy);
		vector<double> radius;
		vector<vector2> center;
		todir = todir.normalize();
		for (double i = 0; i < n; i++){
			double x, y, r;
			cin >> x >> y >> r;
			radius.push_back(r);
			vector2 vbuf = vector2(x, y);
			center.push_back(vbuf);
		}
		vector<double> ret = solve(here, todir, center, radius);
		for (double i = 0; i < ret.size(); i++){ cout << ret[i] << " "; }cout << endl;
	}
	system("pause");
}