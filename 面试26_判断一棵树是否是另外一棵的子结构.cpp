#include<iostream>
#include<string.h>
using namespace std;
/*����26_�����ӽṹ
�������ö�����A��B���ж�B�ǲ���A���ӽṹ

*/
class BinaryTreeNode {
public:
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x) : value(x), left(NULL), right(NULL) {} //��ʼ���б�

};
//������������Ĵ�С�ж�����Ҫ��д�ģ���Ϊ���ܴ��ھ��Ȳ����ԭ���¶���ĸ�������ϸ΢�Ĳ�� 
bool Equal(double num1, double num2) {
	if ((num1-num2)<0.000001&&(num1-num2)>-0.0000001) return true;
	else return false;
}
//��ͬ���ڵ�Ķ��������ж��Ƿ���� 
bool IsTree1hasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2) {
	if (root2==nullptr) return true;
	if (root1==nullptr) return false;

	if (!Equal(root1->value, root2->value)) return false;

	return IsTree1hasTree2(root1->left, root2->left)&&IsTree1hasTree2(root1->right, root2->right);

}
//��һ�����ҵ���ֵͬ�ĸ��ڵ㣬�ڶ�����ʼ�ж����ಿ���Ƿ���ȡ� 
//�ص㣺�ж������е�nullptr��ָ���ж���ν��в����� 
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
�������ı�����Ҫ�����֣�

��1����(��)������������ң�

��2����(��)�����������ң�

��3����(��)����������Ҹ���
*/
//�������
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
	
	string ch = (HasSubTree(root1, root2)==1)?"��":"��";
	cout<<"Tree2�Ƿ���Tree1����������"<<ch<<endl;

	char *a = "abc";
	cout<<*(a+1)<<endl; 
	
	return 0;
}
