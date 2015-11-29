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

double solve(
	vector<vector<double> >& city, 
	vector< vector <vector <double> > >& cache,
	double from, 
	double to,
	double day)
{
	if (day == 0){
		if (from == to){ return 1.0; }
		else{ return 0.0; }
	}
	double& ret = cache[from][to][day];
	if (ret > -0.5){ 
		return ret; 
	}

	ret = 0.0;
	vector<double> tocity;
	for (int i = 0; i < city[from].size(); i++){
		if (city[from][i] == 1){ tocity.push_back(i); }
	}

	for (int i = 0; i < tocity.size(); i++){
		ret += ((solve(city,cache,tocity[i],to,day-1))/tocity.size());
	}
	return ret;
}

int main(){
std::ios::sync_with_stdio(false);
cout.precision(8);
cout.setf(ios::fixed, ios::floatfield);

double T;
cin >> T;
while (T--){
	double N, D, P; //N=number of city, D=day, P=jail
	cin >> N >> D >> P;
	vector<vector<double> > city;
	vector<vector<vector<double> > > cache;
	for (int i = 0; i < 51; i++){
		vector<vector<double> > vvbuf;
		for (int j = 0; j < 51; j++){
			vector<double> vbuf;
			for (int k = 0; k < 101; k++){
				vbuf.push_back(-1);
			}
			vvbuf.push_back(vbuf);
		}
		cache.push_back(vvbuf);
	}

	for (double i = 0; i < N; i++){
		vector<double> vbuf;
		for (double j = 0; j < N; j++){
			double buf;
			cin >> buf;
			vbuf.push_back(buf);
		}
		city.push_back(vbuf);
	}
	double N2;
	cin >> N2;
	while (N2--){
		double Q;
		cin >> Q;
		cout << solve(city, cache, P, Q, D) << endl;
		///
		///cout<<solve(Q)<<endl;
		///

	}

	///////////// city : graph data structure, if(city[i][j]==1) {conn;} else{not conn;}

	/////////////
}

system("pause");
}