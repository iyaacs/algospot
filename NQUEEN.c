#include<stdio.h>
int main(){
int T;
int arr[13]={1,1,0,0,2,10,4,40,92,352,724,2680,14200};
scanf("%d",&T);
while(T--){
int N;
scanf("%d",&N);
printf("%d\n",arr[N]);
}
}