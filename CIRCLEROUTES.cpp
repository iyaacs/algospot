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
using namespace std;

int mystoi(string& s) {
	string hour = "";
	hour += s[0];
	hour += s[1];
	string minute = "";
	minute += s[3];
	minute += s[4];
	int ret = stoi(minute);
	int ihour = stoi(hour);
	ret += (ihour * 60);
	return ret;
}

int main() {
	long long T;
	cin >> T;
	while (T--) {
		string SS, EE, DD, CC;
		cin >> SS >> EE >> DD >> CC;
		
		int S, E, D, C;
		S = mystoi(SS);
		E = mystoi(EE);
		D = mystoi(DD);
		C = mystoi(CC);

		int val;
		int val1; // 차시간표 기준
		int val2; // 차 성능? 기준

		val = E - S;
		val1 = val / D;
		val1++;
		
		val2 = C / D;
		if ((C%D) > 0) { val2++; }

		int ret = val1;
		if (val2 < ret) { ret = val2; }
		cout << ret << endl;
	}
	system("pause");
}