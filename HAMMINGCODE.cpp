#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool XOR(int A,int B){


	return !(((!A) || B) && (A || (!B)));
}

int syndrom(string s){
	int ret = 0;

	if(XOR(XOR(s[0]-'0',s[2]-'0'), XOR(s[4]-'0',s[6]-'0')))
		ret+=1;
	if(XOR(XOR(s[1]-'0',s[2]-'0'), XOR(s[5]-'0',s[6]-'0')))
		ret+=2;
	if(XOR(XOR(s[3]-'0',s[4]-'0'), XOR(s[5]-'0',s[6]-'0')))
		ret+=4;

	return ret;
}

int main(){
	int N;
	cin>>N;
	while(N--){
		string s;
		cin>>s;

		int flip = syndrom(s);
		if(flip != 0){
			if( s[flip-1] == '0')
				s[flip-1] = '1';

			else
				s[flip-1] = '0';
		}
		cout<<s[2]<<s[4]<<s[5]<<s[6]<<endl;

	}


}