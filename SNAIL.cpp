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
using namespace std;
double combi(double front, double end){
	if (end == 0){ return 1; }
	double first = front;
	double second;
	if (end > front - end){ second = front - end; }
	else{ second = end; }
	double ret = 1;
	for (double i = 0; i < second; i++){
		ret *= (first - i);
		ret /= (second - i);
	}
	return ret;
}
int main(){
std::ios::sync_with_stdio(false);
int T;
cin >> T;
while (T--){
	double height, rain;
	cin >> height >> rain;
	double goal = height - rain;
	double answer = 0;
	for (double i = goal; i <= rain; i++){
		answer += combi(rain, i)*pow(0.75,i)*pow(0.25,rain-i);
	}
	cout.precision(10);
	cout.setf(ios::fixed, ios::floatfield);
	cout << answer << endl;
}
system("pause");
}