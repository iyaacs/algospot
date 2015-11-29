#define _CRT_SECURE_NO_WARNINGS
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
struct Node{
	int key;
	int priority, size;
	Node* left, *right;
	Node(const int& _key) :key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
	void setleft(Node* newleft){ left = newleft; calcsize(); }
	void setright(Node* newright){ right = newright; calcsize(); }
	void calcsize(){
		size = 1;
		if (left)size += left->size;
		if (right)size += right->size;
	}
};

typedef pair<Node*, Node*> Nodepair;
Nodepair split(Node* root, int key){
	if (root == NULL){ return Nodepair(NULL, NULL); }
	if (root->key < key){
		Nodepair rs = split(root->right, key);
		root->setright(rs.first);
		return Nodepair(root, rs.second);
	}
	Nodepair ls = split(root->left, key);
	root->setleft(ls.second);
	return Nodepair(ls.first, root);
}
Node* insert(Node* root, Node* node){
	if (root == NULL){ return node; }
	if (root->priority < node->priority){
		Nodepair splitted = split(root, node->key);
		node->setleft(splitted.first);
		node->setright(splitted.second);
		return node;
	}
	else if (node->key < root->key){
		root->setleft(insert(root->left, node));
	}
	else{
		root->setright(insert(root->right, node));
	}
	return root;
}

int countlessthan(Node* root, int key){
	if (root == NULL){ return 0; }
	if (root->key > key){ return countlessthan(root->left, key); }
	int ls = (root->left?root->left->size:0);
	return ls + 1 + countlessthan(root->right, key);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		Node* node = NULL;
		int ret = 0;
		for (int i = 0; i < N; i++){
			int a;
			scanf("%d", &a);
			node = insert(node, new Node(a));
			//cout << i-countlessthan(node, a)+1<<" ";
			ret += (i - countlessthan(node, a)+1);
		}
		//cout << endl;
		printf("%d\n",ret);
	//	cout << ret << endl;
	}
	system("pause");
}