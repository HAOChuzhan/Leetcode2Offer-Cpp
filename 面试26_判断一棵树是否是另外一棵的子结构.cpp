#include<iostream>
#include<string.h>
using namespace std;
/*面试26_树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构

*/
class BinaryTreeNode {
public:
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x) : value(x), left(NULL), right(NULL) {} //初始化列表

};
//计算机浮点数的大小判断是需要重写的，因为可能存在精度不足的原因导致定义的浮点数有细微的差别 
bool Equal(double num1, double num2) {
	if ((num1-num2)<0.000001&&(num1-num2)>-0.0000001) return true;
	else return false;
}
//相同根节点的二叉树来判断是否都相等 
bool IsTree1hasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	if (root2==nullptr) return true;
	if (root1==nullptr) return false;

	if (!Equal(root1->value, root2->value)) return false;

	return IsTree1hasTree2(root1->left, root2->left)&&IsTree1hasTree2(root1->right, root2->right);

}
//第一步是找到相同值的根节点，第二步开始判断其余部分是否相等。 
//重点：判断条件中的nullptr空指针判断如何进行操作。 
bool HasSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	bool result = false;

	if (root1!=nullptr&&root2!=nullptr) {
		if (Equal(root1->value, root2->value)) result = IsTree1hasTree2(root1, root2);
		if (!result) result = HasSubTree(root1->left, root2);
		if (!result) result = HasSubTree(root1->right, root2);
	}

	return result;
}

/*
二叉树的遍历主要有三种：

（1）先(根)序遍历（根左右）

（2）中(根)序遍历（左根右）

（3）后(根)序遍历（左右根）
*/
//中序遍历
void inorder(BinaryTreeNode* root) {
	if (root!=nullptr) {
		inorder(root->left);
		cout<<root->value<<endl;
		inorder(root->right);
	}
} 

int main () {
//	double a = 2;
//	double b = 2;
//	cout<<(a==b)<<endl;
	
	BinaryTreeNode* root1 = new BinaryTreeNode(8); //(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* root2 = new BinaryTreeNode(8);
	root1->left = new BinaryTreeNode(8);
	root1->right = new BinaryTreeNode(7);
	root1->left->left = new BinaryTreeNode(9);
	root1->left->right = new BinaryTreeNode(3);
	root1->left->right->left = new BinaryTreeNode(4);
	root1->left->right->right = new BinaryTreeNode(7);
	
	root2->left = new BinaryTreeNode(9);
	root2->right = new BinaryTreeNode(2);
	
	inorder(root1);
	
	string ch = (HasSubTree(root1, root2)==1)?"是":"否";
	cout<<"Tree2是否是Tree1的子树？："<<ch<<endl;

	char *a = "abc";
	cout<<*(a+1)<<endl; 
	
	return 0;
}
