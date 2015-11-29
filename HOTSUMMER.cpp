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
#define INF 987654321
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int sum;
		cin>>sum;
		for(int i=0;i<9;i++){
			int buf;
			cin>>buf;
			sum-=buf;
		}
		if(sum>=0){cout<<"YES"<<endl;}
		else{cout<<"NO"<<endl;}
	}
}