#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <functional> 
#include <deque>
#include <set>
#include <memory>
using namespace std;
class Tri  {
private:
	map<char, shared_ptr<Tri> > nodes;
	int cnt;
	bool isWord;
public:
	Tri() { 
		cnt = 0; isWord = 0; }

	void Insert(shared_ptr<Tri> ptr, string& s) {
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (ptr->nodes[c] == NULL) {
				ptr->nodes[c] = make_shared<Tri>();
			}
			ptr = ptr->nodes[c];
			ptr->cnt++;
		}
		ptr->isWord = true;
	}

	bool Search(shared_ptr<Tri> ptr, string& s) {
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (ptr->nodes[c] == NULL) { return false; }
			ptr = ptr->nodes[c];
		}
		return ptr->isWord;
	}

	void Delete(shared_ptr<Tri> ptr, string& s) {
		if (!Search(ptr, s)) { return; }
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			ptr = ptr->nodes[c];
			ptr->cnt--;
		}
		ptr->isWord = false;
	}

	int GetResult (shared_ptr<Tri> ptr, deque<string>& dq) {
		int ret = 0;
		for (auto it = dq.begin(); it != dq.end(); it++) {
			bool flag = false;
			auto ref = ptr;

			for (int i = 0; i < (*it).length(); i++) {
				char c = (*it)[i];
				ref = ref->nodes[c];
				if (ref->cnt == 1) { ret += (i + 1); flag = true; break; }
			}
			if (!flag) { ret += (*it).length(); }
		}
		return ret;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		deque<string> sDeque;
		shared_ptr<Tri> tri = make_shared<Tri>();
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			sDeque.push_back(s);
			tri->Insert(tri, s);
		}
		int mmin = 1987654321;
		for (int i = 0; i < N; i++) {
			string s = sDeque.front();
			sDeque.pop_front();
			tri->Delete(tri, s);
			mmin = min(mmin, tri->GetResult(tri, sDeque));
			tri->Insert(tri, s);
			sDeque.push_back(s);
		}
		cout << mmin << endl;
	}
}