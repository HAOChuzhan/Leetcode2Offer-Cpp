#include<iostream>

using namespace std;
/*
����36 - �Ѷ���������ת����һ�������˫������

��������˳��������ǿ������뵽 �����������
Ȼ����ǿ����������������  ���ǿ������뵽��һ����������תΪ˫������ķ�����

����һ��Last�Ŀ�ָ�룬ÿ��ѭ����ʱ�򣬶������ָ��ָ��ǰһ���ڵ㣬�����Ϳ��������������ڵ�֮������ӡ� 
*/
struct Tree {
	int val;
	Tree* left;
	Tree* right;
};
void ConvertNode(Tree* pNode, Tree** LastNode) {
	Tree * pCurrent = pNode;
	if (pCurrent->left!=nullptr) 
		ConvertNode(pCurrent->left, LastNode);
	/*==========================*/
	pCurrent->left = *LastNode;
	if (*LastNode!=nullptr) 
		(*LastNode)->right = pCurrent;
	
	*LastNode = pCurrent;
	/*==========================*/
	if (pCurrent->right!=nullptr) 
		ConvertNode(pCurrent->right, LastNode);
	
}

Tree * Convert(Tree* root) {
	if (root==nullptr) return nullptr;
	Tree* LastNode = nullptr;
	ConvertNode(root, &LastNode);
	
	Tree* ListRoot = LastNode;
	while (ListRoot!=nullptr&&ListRoot->left!=nullptr) 
		ListRoot = ListRoot->left;
	
	return ListRoot;
}


int main () {
	/*�����������������������ԡ�����������������������*/ 
	Tree* root = new Tree(); root->val = 10;
	root->left = new Tree(); root->left->val = 6;
	root->right = new Tree(); root->right->val = 14;
	root->left->left = new Tree(); root->left->left->val = 4;
	
	
	Tree* ListRoot = nullptr;
	ListRoot = Convert(root);
	
	/*================��ӡ���ԵĽ��=================*/ 
	cout<<"˫�������ͷ�ڵ��ǣ�"<<ListRoot->val<<endl; 
	cout<<"˫������Ϊ��";
	while (ListRoot!=nullptr) {
		cout<<ListRoot->val<<"->";
		ListRoot = ListRoot->right;
	}
	cout<<"NULL"<<endl; 
	
	return 0;
} 
