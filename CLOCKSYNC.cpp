#define INF 1987654321
#define SWITCH 10
#define CLOCK 16
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

const char linked[SWITCH][CLOCK+1] = {
	"1110000000000000",
	"0001000101010000",
	"0000100000100011",
	"1000111100000000",
	"0000001110101000",
	"1010000000000011",
	"0001000000000011",
	"0000110100000011",
	"0111110000000000",
	"0001110001000100",

};
bool areAligned(const vector<int>& clocks){
	for (int i = 0; i < CLOCK; i++){
		if (clocks[i] != 12){ return false; }
	}
	return true;
}
void push(vector<int>& clocks, int num){
	for (int i = 0; i < CLOCK; i++){
		if (linked[num][i] == '1'){ 
			clocks[i] += 3;
		if (clocks[i] == 15){ clocks[i] = 3; }
		}
	}
}
int solve(vector<int>& clocks, int num){
	if (num == SWITCH)
	{
		if (areAligned(clocks)){ return 0; }
		else{ return INF; }
	}
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++){
		ret = min(ret, cnt + solve(clocks, num + 1));
		push(clocks, num);
	}
	return ret;
}
int main(){
std::ios::sync_with_stdio(false);
//////////
int T;
cin >> T;
while (T--){
	vector<int> clock;
	for (int i = 0; i < CLOCK; i++){
		int buf;
		cin >> buf;
		clock.push_back(buf);
	}
	int ret = solve(clock, 0);
	if (ret == INF){ cout << -1 << endl; }
	else{ cout << ret << endl; }
}
//////////
system("pause");
}