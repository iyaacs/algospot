#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

const double SIZE = 29.0;
const long long ISIZE = 29;
const long long PIVOT = (1 << ISIZE) - 1;

//OverFlow 허용
void MoveToRight(vector<long long>& bits2, bool rightBit, long long s1len) {
	long long lastGroup = bits2.size() - 1;
	//long long validLeftBitPos =( s1len % (long long(SIZE+1)))-1;
	long long validLeftBitPos = s1len-1;
	for (long long i = lastGroup; i > 0; i--) { validLeftBitPos -= ISIZE; }
	long long validBit = 1 << validLeftBitPos;
	for (long long i = lastGroup; i >= 0; i--) {
		long long nextBit = bits2[i] & validBit;
		bits2[i] = bits2[i] << 1;
		bits2[i] |= rightBit;
		rightBit = nextBit;
		validBit = (1 << ((long long)(SIZE) - 1));
	}
}


//bit 관련 처리는 여기서 다함
bool IsAllHug(vector<long long>& bits1, vector<long long>& bits2, long long s1len) {
	long long lastGroup = bits1.size() - 1;
	long long validBitCount = s1len;
	for (long long i = 0; i < lastGroup; i++) {
		validBitCount -= ISIZE;
		long long b1 = bits1[i] & PIVOT;
		long long b2 = bits2[i] & PIVOT;
		if (((b1 | b2)&PIVOT) != PIVOT) { return false; }
	}
	//유효비트 개수 가능 : 1 <= z <= SIZE
	//long long validBitCount = s1len % (long long(SIZE + 1));
	long long _pivot = (1 << validBitCount) - 1;
	long long _b1 = bits1[lastGroup] & _pivot;
	long long _b2 = bits2[lastGroup] & _pivot;
	//cout << validBitCount << " " << _pivot << " " << _b1 << " " << _b2 << endl;
	if (((_b1 | _b2)&_pivot) != _pivot) { return false; }
	return true;
}
long long solve(string& s1, string& s2) {

	vector<long long> bits1;
	vector<long long> bits2;

	long long len1 = s1.length();
	long long len2 = s2.length();
	for (long long i = 0; i < ceil(len1 / SIZE); i++) {
		long long left = i * SIZE;
		long long right = (i + 1)*SIZE;
		if (right > len1) { right = len1; }
		long long val1 = 0;
		long long val2 = 0;
		long long bitCnt = 0;
		for (long long j = right-1; j >= left; j--) {
			if (s1[j] == 'F') { val1 |= (1 << bitCnt); }
			if (s2[j] == 'F') { val2 |= (1 << bitCnt); }
			bitCnt++;
		}
		bits1.push_back(val1);
		bits2.push_back(val2);
	}

	long long ret = 0;
	long long cnt = len2 - len1;
	long long right = len1;
	for (long long i = 0; i <= cnt; i++) {
		if (IsAllHug(bits1, bits2, len1)) { ret++; }
		if (right >= len2) { break; }
		bool rightbit = false;
		if (s2[right] == 'F') { rightbit = true; }

		//cout << right << " " << s2[right] << " "<<rightbit<< endl;
		MoveToRight(bits2, rightbit, len1);
		right++;
	}
	return ret;
}
int main() {
	long long T;
	cin >> T;
	while (T--) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		cout << solve(s1, s2) << endl;
	}
	system("pause");
}