#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int T;
  
  cin>>T;
  while(T--)
  {
int leng;

  vector<int> arr,arr2;
    cin>>leng;
    for(int i=0;i<leng;i++)
    {
	int buf;
	cin>>buf;
	arr.push_back(buf);
        arr2.push_back(i+1);
    }
  vector<int> result(leng,0);

     for(int i=arr2.size()-1;i>=0;i--)
    {
      result[i]=arr2[i-arr[i]];
      arr2.erase(arr2.end()-arr[i]-1);
    }
      result[0]=arr2[0];
    
      for(int j=0;j<leng;j++)
      { 
        cout<<result[j]<<" ";
      }cout<<endl;
      arr2.clear();
  }
}