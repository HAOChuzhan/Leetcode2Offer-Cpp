#include<iostream>

using namespace std;
/*
面试27--讲二叉树镜像翻转，所以该二叉树必须是满二叉树
然后解决方法是递归 
*/ 
class Tree
{
public:
	int val;
	Tree* left;
	Tree* right;
	Tree(int x): val(x), left(nullptr), right(nullptr) {}		
};
//这里借用了递归遍历的思想，遍历每个节点，然后将其左右孩子进行交换，
//递归头是该节点为空，和该节点的左右孩子都为空。 
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
