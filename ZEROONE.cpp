#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
int main(){
	//int* arr = (int*)malloc(1000010);
	vector<int> arr;
	arr.push_back(0);
	int arrsize = 0;
	char a = 'a';
	int plusval = 0;

	for (int i = 0;; i++){
		char b = getchar();
		if (b == '\n'){ arr.push_back(plusval); break; }
		if (i == 0){ a = b; continue; }
		if (a != b){ plusval++; a = b; }
		arr.push_back(plusval);
	}

	int T;
	scanf("%d", &T);
	while (T--){
		int start;
		int end;

		scanf("%d", &start);
		scanf("%d", &end);
		if (end < start){ int buf = start; start = end; end = buf; }

		if (arr[start] == arr[end]){ printf("Yes\n"); }
		else{ printf("No\n"); }

	}

	system("pause");
}