#include<iostream>

using namespace std;
/*
面试36 - 把二叉搜索树转换成一个排序的双向链表

这个排序的顺序就让我们可以联想到 ——中序遍历
然后就是考虑如何连接两个点  我们可以联想到将一个单向链表转为双向链表的方法：

引入一个Last的空指针，每次循环的时候，都将这个指针指向前一个节点，这样就可以来进行两个节点之间的连接。 
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
	/*——————————测试————————————*/ 
	Tree* root = new Tree(); root->val = 10;
	root->left = new Tree(); root->left->val = 6;
	root->right = new Tree(); root->right->val = 14;
	root->left->left = new Tree(); root->left->left->val = 4;
	
	
	Tree* ListRoot = nullptr;
	ListRoot = Convert(root);
	
	/*================打印测试的结果=================*/ 
	cout<<"双向链表的头节点是："<<ListRoot->val<<endl; 
	cout<<"双向链表为：";
	while (ListRoot!=nullptr) {
		cout<<ListRoot->val<<"->";
		ListRoot = ListRoot->right;
	}
	cout<<"NULL"<<endl; 
	
	return 0;
} 
