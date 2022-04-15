#include<iostream>

using namespace std;
/*
����27--������������ת�����Ըö�������������������
Ȼ���������ǵݹ� 
*/ 
class Tree
{
public:
	int val;
	Tree* left;
	Tree* right;
	Tree(int x): val(x), left(nullptr), right(nullptr) {}		
};
//��������˵ݹ������˼�룬����ÿ���ڵ㣬Ȼ�������Һ��ӽ��н�����
//�ݹ�ͷ�Ǹýڵ�Ϊ�գ��͸ýڵ�����Һ��Ӷ�Ϊ�ա� 
void MirrorReverse(Tree *root) {
	if (root==nullptr) return;
	if (root->left==nullptr&&root->right==nullptr) return;
	Tree* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	
	if (root->left)  MirrorReverse(root->left);
	if (root->right) MirrorReverse(root->right);
} 
void inorder(Tree* root) {
	if (root!=nullptr) {
		
		inorder(root->left);
		cout<<root->val<<endl;
		inorder(root->right);
	}
}

int main () {
	Tree* root = new Tree(2);
	root->left = new Tree(3);
	root->right = new Tree(4);
	root->left->left = new Tree(5);
	
	MirrorReverse(root);
	inorder(root);
	
	return 0;
} 
