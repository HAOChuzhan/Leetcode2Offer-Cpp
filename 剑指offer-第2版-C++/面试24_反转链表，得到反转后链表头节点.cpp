#include<iostream>

using namespace std;

/*面试24：反转链表*/
struct ListNode{
	int val;
	ListNode* next;
}; 
void PrintList(ListNode* phead) {
	ListNode* head = phead->next; 
	cout<<"链表为：";
	while (head) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
//头插法创建链表 (再次复习一遍)
ListNode* CreateList() {
	ListNode* head,*p;
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head==nullptr) return head;
	
	head->next = NULL;
	int x;
	cout<<"请输入组成链表的节点数字，以0结束："<<endl;
	cin>>x;
	while(x) {
		p = (ListNode*)malloc(sizeof(ListNode));
		if (p==nullptr) return p;
		p->val = x;
		/*重点地方，先把节点接入，再让头节点的next等于该节点*/ 
		p->next = head->next;
		head->next = p;
		
		cin>>x;
	}
	return head;
}
/*
注意三点情况：
1.输入的头节点为空
2.输入的链表只有一个节点
3.输入的链表有多个节点 
*/
ListNode* ReverseList(ListNode* head) {
	ListNode* ReverseHead = nullptr;
	ListNode* Node = head;
	ListNode* PreN = nullptr;
	while (Node!=nullptr) {
		ListNode* pnext = Node->next;
		if (pnext==nullptr) ReverseHead = Node;
		Node->next = PreN;
		
		PreN = Node;
		Node = pnext;
	
	}
	return ReverseHead;
}

int main() {
	ListNode* head = CreateList();
	cout<<"链表的头节点是："<<head->next->val<<endl;
	PrintList(head);
	
	ListNode*newHead = ReverseList(head->next);
	cout<<"链表的头节点是："<<newHead->val<<endl;
	cout<<"反转后的链表是："; 
	ListNode* phead = newHead;
	while (phead!=nullptr) {
		cout<<phead->val<<"->";
		phead = phead->next;
	} 
	cout<<"NULL"<<endl;
	return 0;
} 
