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

int main() {
	long long T;
	cin >> T;
	while (T--) {
		long long N, M, r0, c0, r, c, A, B;
		cin >> N >> M >> r0 >> c0 >> r >> c >> A >> B;
		//(r0,c0) to (r,c), (A,B) is max bound
		if (r < r0) {
			long long cha = r0 - r;
			r += cha;
			r += cha;
		}
		if (c < c0) {
			long long cha = c0 - c;
			c += cha;
			c += cha;
		}
		//r은 무조건 r0보다 오른쪽으로, c는 무조건 c0보다 아래쪽에 존재.
		long long cha_r = r - r0;
		long long cha_c = c - c0;
		long long mox_r = cha_r / A;
		long long mox_c = cha_c / B;
		long long mod_r = cha_r%A;
		long long mod_c = cha_c%B;
		
		long long ret = 0;
		ret += mox_r;
		ret += mox_c;
		if (mod_r > 0) { ret++; }
		if (mod_c > 0) { ret++; }
		cout << ret << endl;
	}
	system("pause");
}