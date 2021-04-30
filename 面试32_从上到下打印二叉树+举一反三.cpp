#include<iostream>
#include<queue>
using namespace std;
typedef int element;

class Tree
{
public:	
	element val;
	Tree *left;
	Tree *right;
	Tree(element x): val(x), left(nullptr), right(nullptr) {}
	
};
void hierarchy_queue(Tree *root) {
	if (root==nullptr) return;
	queue<Tree*> q;
	q.push(root);
	while (q.empty()==false) {
		cout<<q.front()->val<<" ";
		if (q.front()->left!=nullptr) {
			q.push(q.front()->left);
		}
		if (q.front()->right!=nullptr) {
			q.push(q.front()->right);
		}
		q.pop();
	}
}
void hierarchy_array(Tree *root) {
	if (root==nullptr) return;
	Tree* q[100];
	int in, out = 0;
	q[in++] = root;
	
	while (in>out) {
		
		if (q[out]!=nullptr) {
			cout<<q[out]->val<<" ";
			q[in++] = q[out]->left;
			q[in++] = q[out]->right;
		}
		out++;
	}
}
/*=========================��һ����==============================*/ 
//���д������´�ӡ������ 
void hierarchy_array(Tree*root) {
	if (root==nullptr) return;
	queue<Tree*> q;
	q.push(root);
	int toPrint = 0;
	int level = 1;
	while (q.empty()) {
		cout<<q.front()->val<<" ";
		if (q.front()->left!=nullptr) {
			
		}
		if (q.front()->right!=nullptr) {
			
		}
	}
	
	
}




//֮���δ�ӡ������
void hierarchy_array(Tree* root) {
	
	
}


 
int main() {
	Tree* root = new Tree(4);
	root->left = new Tree(2);
	
	root->left->left = new Tree(4);
	root->left->right = new Tree(5);
	
	cout<<"���ö���ʵ�ֲ�α�����";
	hierarchy_queue(root);
	cout<<"\n��������ʵ�ֲ�α�����" ;
	hierarchy_array(root);
	
	return 0;
}
