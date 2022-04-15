#include<iostream>

using namespace std;
/*
面试35 - 复杂链表的复制
三步走：
	第一步：复制原始链表的所有节点，并连接到原始节点的后边；
	第二步：复制其sibling指针，对应的复制节点相互连接；
	第三步：把整个长链表拆分成两个链表。 
*/
struct ListNode{
	int val;
	ListNode* next;
	ListNode* sibling;
};

//class ListNode {
//public:
//	int val;
//	ListNode* next;
//	ListNode(int x): val(x), next(nullptr) {}
//};

//复制原链表的节点 
void CloneList(ListNode* head) {
	ListNode* pNode = head;
	while (pNode!=nullptr) {
		ListNode* pClone = new ListNode();
		pClone->val = pNode->val;
		pClone->next = pNode->next;
		pClone->sibling = nullptr;
		
		pNode->next = pClone;
		pNode = pClone->next;
	}
} 
//将复制的节点的sibling指针也对应有值 
void Clonesibling(ListNode* head) {
	ListNode *pNode = head;
	while (pNode!=nullptr) {
		ListNode* pClone = pNode->next;
		if (pNode->sibling!=nullptr) {
			pClone->sibling = pNode->sibling->next;
		}
		pNode = pClone->next;
	}
} 

//将复制的长链表拆开 
ListNode* ReconnectNode(ListNode* head) {
	ListNode* pNode = head;
	ListNode* pClone = nullptr;
	ListNode* pCloneNode = nullptr;
	
	if (pNode!=nullptr) {
		pClone = pNode->next;
		pCloneNode = pNode->next;
		pNode->next = pCloneNode->next;
		
		pNode = pNode->next; 
	}
	while (pNode!=nullptr) {
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;
		pNode->next = pCloneNode->next;
		pNode = pNode->next; 
	}
	return pClone;
}
//将上边的三个步骤合起来 
ListNode* Clone(ListNode* head) {
	CloneList(head);
	Clonesibling(head);
	return ReconnectNode(head);
}

int main () {
//	ListNode* head = new ListNode(3);
//	head->next = new ListNode(2);
	int arr[5] = {1,2,3,4,5};
	cout<<*arr<<endl;
	cout<<&arr+1<<endl;
	cout<<*(*(&arr+1)-1)<<endl;
	
	
	
	return 0;
} 
