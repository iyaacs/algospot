#include<iostream>
#include<string>
using namespace std;
int main(){
	int T;
	cin>>T;
	int kk=1;
	while(T--){
		int n;
		string str;
		cin>>n;
		cin>>str;
		cout<<kk<<" ";
		for(int i=0;i<str.length();i++){
			if(i+1==n){continue;}
			cout<<str[i];
			
		}
		cout<<endl;
	kk++;	
	}
	}