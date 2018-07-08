#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <functional> 
using namespace std;
class Tri {
private:
	int first;
	int terminal;
	map<int, Tri*> nodes;
public:
	Tri() {
		first = -1;
		terminal = -1;
	}
	void insert(int& no, string& s) {
		auto ptr = this;
		for (int i = 0; i < s.size(); i++) {
			if (ptr->nodes.find(s[i]) == ptr->nodes.end()) {
				ptr->nodes[s[i]] = new Tri();
			}
			ptr = ptr->nodes[s[i]];
			if (ptr->first == -1) { ptr->first = no; }			
		}
		ptr->terminal = no;
	}

	//문자열이 Tri에 속하나 검사.
	Tri* search(string& str) {
		auto ptr = this;
		for (int i = 0; i < str.length(); i++) {
			if (ptr->nodes.find(str[i]) == ptr->nodes.end()) { return 0; }
			ptr = ptr->nodes[str[i]];
		}
		if (ptr->terminal == -1) { 
			return 0; 
		}
		return ptr;
	}

	int GetMinType(string& s) {
		auto endPtr = search(s);
		if (endPtr == 0) { return s.length(); }
		int ret = 1;
		auto ptr = this;
		for (int i = 0; i < s.length(); i++) {
			ptr = ptr->nodes[s[i]];
			ret++;
			if (ret > s.length()) { return s.length(); }
			if (ptr->first == endPtr->terminal) { return ret; }
		}
		return ret;
	}
	int GetMinType(vector<string>& strArr) {
		int ret = 0;
		for (int i = 0; i < strArr.size(); i++) {

			ret += GetMinType(strArr[i]);
		}
		ret += strArr.size() - 1;
		return ret;
	}

};
int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		Tri* tri = new Tri();
		vector<pair<int, string> > input;
		for (int i = 0; i < N; i++) {
			string s;
			int freq;
			cin >> s >> freq;
			input.push_back(make_pair(-freq, s));
		}
		sort(input.begin(), input.end());

		for (int i = 0; i < N; i++) {
			tri->insert(i, input[i].second);
		}

		vector<string> sArr;
		for (int i = 0; i < M; i++) {
			string s;
			cin >> s;
			sArr.push_back(s);
		}
		cout << tri->GetMinType(sArr) << endl;
	}


	//system("pause");
}