#include<iostream>
#include<vector>
using namespace std;
/*
����28_�Գƶ����� �ж�һ�ö������ǲ��ǶԳƵģ����侵���������һ�����ǶԳƵ� 

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
	string ch = isSystematic(root)==1?"��":"��"; 
	cout<<"�ö������Ƿ��ǶԳƵģ�"<<ch<<endl;
	
//	vector<vector<int> > shenjing(3);
//	shenjing[0] = [1,2,3];
//	cout<<array[0][2]<<endl;
	
	return 0;
} 
