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
		map<int,int> xcount;
		map<int,int> ycount;
		for(int i=0;i<3;i++){
			int x,y;
			cin>>x>>y;
			xcount[x]++;
			ycount[y]++;
		}
    map<int,int>::iterator it;
    int retx, rety;
    for(it=xcount.begin(); it!=xcount.end(); it++){
    if(it->second==1){retx=it->first; break;}
    }
    for(it=ycount.begin(); it!=ycount.end(); it++){
    if(it->second==1){rety=it->first; break;}
    }
    cout<<retx<<" "<<rety<<endl;
		    
		
	}
}