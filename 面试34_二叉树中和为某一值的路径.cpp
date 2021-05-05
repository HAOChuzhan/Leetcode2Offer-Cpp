#include<iostream>
#include<vector>
using namespace std;

/*
����34_�������к�Ϊĳһֵ��·��. �Ӹ��ڵ㵽Ҷ�ӽڵ� 
*/ 
typedef int element;

class Tree
{
public:	
	element val;
	Tree *left;
	Tree *right;
	Tree(element x): val(x), left(nullptr), right(nullptr) {}
	
};
void Find(Tree* root, int exp, vector<int> &res, int cur) {
	cur += root->val;
	res.push_back(root->val);
	bool isLeaf = (root->left==nullptr)&&(root->right==nullptr);
	if (cur==exp && isLeaf) {
		cout<<"A path is finded!"<<endl;
		for (auto iter=res.begin(); iter!=res.end(); iter++) 
			cout<<*iter<<"->";
		cout<<"NULL"<<endl;
	}
	//�������Ҷ�ӽڵ㣬��������������ӽڵ�,������õ���ǰ�������˼�룬���Ǹ��ڵ��������Һ��ӽڵ㡣 
	if (root->left!=nullptr) 
		Find(root->left, exp, res, cur);
	if (root->right!=nullptr)
		Find(root->right, exp, res, cur);
	
	res.pop_back(); 
	
}


void FindPath(Tree* root, int exp) {
	if (root==nullptr) return;
	vector<int> res;
	int currentSum=0;
	Find(root, exp, res, currentSum);	
	
} 

int main () {
	
	Tree* root = new Tree(10);
	root->left = new Tree(5);
	root->right = new Tree(12);
	root->left->left = new Tree(4);
	root->left->right = new Tree(7);
	
	FindPath(root, 22);
	
	return 0;
} 
