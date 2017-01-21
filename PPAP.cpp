#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<int> pmatch(string& s) {
	int m = s.length();
	vector<int> fixmaxlen(m, 0);
	int start = 1;
	int matched = 0;
	while (true) {
		if (start + matched >= m) { break; }
		char c1 = s[start + matched];
		char c2 = s[matched];
		if (c1 == c2) {
			matched++;
			fixmaxlen[start + matched - 1] = matched;
		}
		else {
			if (matched == 0) { start++; }
			else { 
				start += matched;
				start -= fixmaxlen[matched - 1];
				matched = fixmaxlen[matched - 1];
			}
		}
	}
	return fixmaxlen;
}

vector<int> findSubstring(string& haystack, string& needle) {
	int n = haystack.length();
	int m = needle.length();
	vector<int> ret;
	vector<int> fixmaxlen = pmatch(haystack);
	int start = 0;
	int matched = 0;
	while (true) {
		if (start > n - m) { break; }
		char c1 = 'a';
		char c2 = 'b';
		if (start + matched < n) {
			c1 = haystack[start + matched];
		}
		if (matched < m) {
			c2 = needle[matched];
		}
		if (c1 == c2 && matched < m) {
			matched++;
			if (matched == m) { ret.push_back(start); }
		}
		else {
			if (matched == 0) { start++; }
			else { 
				start += matched;
				start -= fixmaxlen[matched - 1];
				matched = fixmaxlen[matched - 1];
			}
		}
	}
	return ret;
}

int main() {
	int L, R;
	string P;
	cin >> L >> R >> P;
	string s = "pen-pineapple-apple-pen/";
	string s2 = "";
	for (int i = 0; i < 42000; i++) {
		s2 += s;
	}

	L--;
	R -= L;
	string haystack = s2.substr(L, R);
	cout << findSubstring(haystack, P).size() << endl;

}