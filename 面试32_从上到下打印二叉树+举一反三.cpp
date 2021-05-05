#include<iostream>
#include<queue>
#include<stack>
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
/*=========================举一反三==============================*/ 
//分行从上至下打印二叉树 
void hierarchy_array_row(Tree* root) {
	if (root==nullptr) return;
	queue<Tree*> q;
	q.push(root);
	int toPrint = 0;
	int level = 1;
	while (!q.empty()) {
		cout<<q.front()->val<<" ";
		if (q.front()->left!=nullptr) {
			q.push(q.front()->left);
			toPrint++;
		}
		if (q.front()->right!=nullptr) {
			q.push(q.front()->right);
			toPrint++;
		}
		q.pop();
		level--;
		if (level==0) {
			cout<<endl;
			level = toPrint;
			toPrint = 0;
		}
	}
}

//之字形打印二叉树
void hierarchy_array_z(Tree* root) {
	if (root==nullptr) return;
	stack<Tree*> level[2];
	int current = 0;
	int next = 1;
	level[current].push(root);
	
	while (!level[0].empty()||!level[1].empty()) { //只要其中一个堆栈中还存在数据就继续 
		
		Tree* tmp = level[current].top();
		level[current].pop();
		cout<<tmp->val<<" ";
		
		
		if (current==0) {
			if (tmp->left!=nullptr) level[next].push(tmp->left);
			if (tmp->right!=nullptr) level[next].push(tmp->right);
			
		}
		else {
			if (tmp->right!=nullptr) level[next].push(tmp->right);
			if (tmp->left!=nullptr) level[next].push(tmp->left);
			
		}
//		cout<<level[current].empty();
		if (level[current].empty()) {
			cout<<endl;
			current = 0x1^current;
			next = 0x1^next;
		}
	}
	
}


 
int main() {
	Tree* root = new Tree(4);
	root->left = new Tree(2);
	root->right = new Tree(3);
	root->left->left = new Tree(4);
	root->left->right = new Tree(5);
	
	cout<<"利用队列实现层次遍历：";
	hierarchy_queue(root);
	cout<<"\n利用数组实现层次遍历：" ;
	hierarchy_array(root);
	cout<<"\n分行打印二叉树: \n";
	hierarchy_array_row(root);
	cout<<"\n之字形打印二叉树:\n"; //4 3 2 4 5
	hierarchy_array_z(root);
//	cout<<(0x1^0)<<endl; 
	
	return 0;
}
