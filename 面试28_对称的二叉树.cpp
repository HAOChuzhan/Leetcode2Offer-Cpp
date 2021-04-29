#include<iostream>
#include<vector>
using namespace std;
/*
面试28_对称二叉树 判断一棵二叉树是不是对称的，若其镜像和他本身一致则是对称的 

*/ 
class Tree
{
public:
	int val;
	Tree* left;
	Tree* right;
	Tree(int x): val(x), left(nullptr), right(nullptr) {}		
};
bool Systematic(Tree* root1, Tree*root2) {
	if (root1==nullptr) return true;
	if (root1==nullptr&&root2==nullptr) return true;
	if (root1==nullptr||root2==nullptr) return false;
	
	return Systematic(root1->left, root2->right)&&Systematic(root1->right, root2->left);
}

bool isSystematic(Tree *root) {
	
	return Systematic(root, root);
	

}

int main () {
	
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(2);
	root->left->left = new Tree(3);
	root->right->right = new Tree(3);
	string ch = isSystematic(root)==1?"是":"否"; 
	cout<<"该二叉树是否是对称的？"<<ch<<endl;
	
//	vector<vector<int> > shenjing(3);
//	shenjing[0] = [1,2,3];
//	cout<<array[0][2]<<endl;
	
	return 0;
} 
