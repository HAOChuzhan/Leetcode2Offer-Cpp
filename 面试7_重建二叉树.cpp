#include<iostream>

using namespace std;
typedef int ElementType;

struct ListNode{
	int val;
	ListNode* next;
};
struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;	
};

BinaryTreeNode* ConstructCore(int *startpreorder, int* endpreorder, int* startinorder, int* endinorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length);
ListNode* Creat_list() {
	ListNode* head, *p;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr) {
		return head;
	}
	head->next = NULL;
	ElementType x;
	cout<<"输出链表各个节点数，以0结束:"<<endl;
	cin>>x;
	while (x!=0) {
		p = (ListNode*) malloc(sizeof(ListNode));
		p->val = x;
		p->next = head->next;
		head->next = p;
		
		cin>>x;
	}
	return head;
}
ListNode* Creat_List_R() {
	ListNode *head, *p, *tail;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr)
		return head;
	head->next = NULL;
	tail = head;
	ElementType x;
	cout<<"请输入要录入的数以0结束"<<endl;
	cin>>x;
	while (x!=0) {
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = x;
		tail->next = p;
		tail = p;
		tail->next = NULL;
		cin>>x;
	}
	return head;
	
} 
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder==nullptr || inorder==nullptr || length ==0) {
		return nullptr;
	}
	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}
BinaryTreeNode* ConstructCore(int *startpreorder, int* endpreorder, int* startinorder, int* endinorder) {
	int rootvalue = startpreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->val = rootvalue;
	root->left = nullptr;
	root->right = nullptr;
	if (startpreorder == endpreorder) {
		if (startinorder==endinorder && *startpreorder==*endpreorder) {
			return root;
		}
	}
	int *rootinorder = startinorder;
	while (rootinorder<=endinorder&&*rootinorder!=rootvalue) {
		++rootinorder;
	}
	int leftlength = rootinorder-startpreorder;
	int *leftpreorderend = startpreorder + leftlength;
	if (leftlength>0) {
		root->left = ConstructCore(startpreorder+1, leftpreorderend, startinorder, rootinorder-1);
	}
	if (leftlength<endpreorder-startpreorder) {
		root->right = ConstructCore(leftpreorderend+1, endpreorder, rootinorder+1, endinorder);
	}
	return root;
}

int main () {
	int a[] = {1,2,4,7,3,5,6,8};
	int b[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* root = Construct(a, b, 8);
	cout<<"根节点为："<<root->val<<endl;//<<root->right->val;
	cout<<"左子树根节点是："<<root->left->left->right->val<<endl; 
	
	ListNode* phead = Creat_list();
	cout<<"头节点是："<<phead->next->val<<endl;
	
	return 0;
}
